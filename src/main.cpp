#include "Sync_inter.h"

int main()
{
    std::vector<double> cam_t;
    std::vector<double> imu_t; 
    std::vector<Q> imu_q;

    GenTimestampQuaternion( cam_t, imu_t, imu_q);

    Q qc;
    for (const auto& tc : cam_t)
    {
        if (CalImuPose(tc, imu_t, imu_q, qc))
        {
            std::cout << "qc : "
                      << qc.x << "  "
                      << qc.y << "  "
                      << qc.z << "  "
                      << qc.w << "  "
                      << std::endl;
        }
        
    }
    
    return 0;
}
