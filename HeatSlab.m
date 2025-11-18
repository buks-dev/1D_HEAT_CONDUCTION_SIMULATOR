classdef HeatSlab < handle
    % HeatSlab   Simple 1‑D heat conduction model (explicit scheme)
    %   Usage:
    %       slab = heat.HeatSlab(T0, alpha, dx, dt);
    %       slab.step(1000);   % advance 1000 time steps
    %       plot(slab.T);
    %
    properties
        T
        alpha
        dx
        dt
    end
    methods
        function obj = HeatSlab(T0, alpha, dx, dt)
            obj.T = T0(:);
            obj.alpha = alpha;
            obj.dx = dx;
            obj.dt = dt;
        end
        function step(obj, nSteps)
            for n = 1:nSteps
                Tn = obj.T;
                obj.T(2:end-1) = Tn(2:end-1) + ...
                    obj.alpha * obj.dt / obj.dx^2 .* ...
                    (Tn(3:end) - 2*Tn(2:end-1) + Tn(1:end-2));
            end
        end
    end
end