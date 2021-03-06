#ifndef pfopt_mv_optimizer_hpp
#define pfopt_mv_optimizer_hpp

#include "meanvariance.hpp"
#include <coin/IpIpoptApplication.hpp>
#include <string>

namespace pfopt {
    class MVOptimizer {
    public:
        MVOptimizer(int numAssets,
                    double *expectReturn,
                    double *varMatrix,
                    double *lbound,
                    double *ubound,
                    int numConstraints,
                    double *consMatrix = nullptr,
                    double *clb = nullptr,
                    double *cub = nullptr,
                    double riskAversion = 1.,
                    int numFactors=0,
                    double* factorVarMatrix=nullptr,
                    double* factorLoading=nullptr,
                    double* idsync=nullptr,
                    std::string linearSolver="ma27");

        std::vector<double> xValue() const { return mvImpl_->xValue(); }

        double feval() const { return mvImpl_->feval(); }
        int status() const { return status_; }

    private:
        Ipopt::SmartPtr<MeanVariance> mvImpl_;
        Ipopt::SmartPtr<Ipopt::IpoptApplication> app_;
        Ipopt::ApplicationReturnStatus status_;
    };
}

#endif