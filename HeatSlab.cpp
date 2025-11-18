#include "mex.hpp"
#include "mexAdapter.hpp"
#include <vector>
#include <stdexcept>

using namespace matlab::mex;
using namespace matlab::data;

class HeatSlab {
private:
    std::vector<double> T; // Temperature array
    double alpha;         // Thermal diffusivity
    double dx;            // Spatial step
    double dt;            // Time step
    double r;             // Stability parameter: alpha * dt / (dx * dx)

public:
    HeatSlab(const TypedArray<double>& T0, double alpha, double dx, double dt)
        : alpha(alpha), dx(dx), dt(dt) {
        // Copy initial temperatures to T
        T = std::vector<double>(T0.begin(), T0.end());
        r = alpha * dt / (dx * dx);
    }

    // Perform one time step of explicit finite-difference
    void step() {
        if (T.size() < 3) {
            return; // Skip if too few elements (rely on MATLAB validation)
        }
        std::vector<double> T_new(T.size());
        T_new[0] = T[0]; // Fixed left boundary
        T_new[T.size() - 1] = T[T.size() - 1]; // Fixed right boundary

        // Update interior points
        for (size_t i = 1; i < T.size() - 1; ++i) {
            T_new[i] = T[i] + r * (T[i + 1] - 2 * T[i] + T[i - 1]);
        }
        T = T_new; // Update temperature array
    }

    // Run simulation for specified steps
    void simulate(int steps) {
        for (int n = 0; n < steps; ++n) {
            step();
        }
    }

    // Get current temperature array
    std::vector<double> getTemperatures() const {
        return T;
    }
};

class MexFunction : public matlab::mex::Function {
private:
    ArrayFactory factory;
    std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();

public:
    void operator()(ArgumentList outputs, ArgumentList inputs) override {
        // Validate input arguments
        if (inputs.size() != 5) {
            matlabPtr->feval(u"error",
                0, std::vector<Array>({ factory.createScalar("Five inputs required: T0, alpha, dx, dt, steps") }));
            return;
        }
        if (outputs.size() > 1) {
            matlabPtr->feval(u"error",
                0, std::vector<Array>({ factory.createScalar("Only one output allowed") }));
            return;
        }

        // Extract inputs
        TypedArray<double> T0 = std::move(inputs[0]); // Assume T0 is numeric (validated by MATLAB)
        double alpha = inputs[1][0];
        double dx = inputs[2][0];
        double dt = inputs[3][0];
        int steps = static_cast<int>(inputs[4][0]);

        // Validate numeric inputs
        if (alpha <= 0 || dx <= 0 || dt <= 0 || steps <= 0) {
            matlabPtr->feval(u"error",
                0, std::vector<Array>({ factory.createScalar("alpha, dx, dt, and steps must be positive") }));
            return;
        }

        // Check numerical stability
        double r = alpha * dt / (dx * dx);
        if (r > 0.5) {
            matlabPtr->feval(u"error",
                0, std::vector<Array>({ factory.createScalar("Unstable parameters: alpha*dt/dx^2 <= 0.5 required") }));
            return;
        }

        // Run simulation
        HeatSlab slab(T0, alpha, dx, dt);
        slab.simulate(steps);

        // Create output array
        std::vector<double> T_out = slab.getTemperatures();
        TypedArray<double> output = factory.createArray<double>({ T_out.size(), 1 });
        std::copy(T_out.begin(), T_out.end(), output.begin());

        outputs[0] = output;
    }
};