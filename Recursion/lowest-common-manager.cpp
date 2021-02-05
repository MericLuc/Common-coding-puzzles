/*!
 * @brief Lowest Common Manager.
 *        From https://www.algoexpert.io/questions/Lowest%20Common%20Manager
 */

#include <vector>

struct OrgChart {
    char                   name;
    std::vector<OrgChart*> directReports{};

    OrgChart(char p_name) : name(p_name) {}
    
    void addDirectReports(std::vector<OrgChart*> directReports);
};

using OC = OrgChart;

struct LCM { int reports; OC* name; };

LCM getLCM(OC* topM, OC* r1, OC* r2) {
    int reports{ 0 };
    if ( !topM )                    { return {0, nullptr}; }
    if ( topM == r1 || topM == r2 ) { ++reports; }
    for ( OC* dr : topM->directReports ) {
        LCM lcm{ getLCM(dr, r1, r2) };
        reports += lcm.reports;
        if ( lcm.reports == 2 ) { return { 2, lcm.name }; }
    }
    return { reports, topM };
}

OC* getLowestCommonManager(OC* topM, OC* r1, OC* r2) {
    return getLCM(topM, r1, r2).name;
}