#pragma once
#include "problem1.h"


class MAPF : public Problem {
private:
    int timestep;
    int timesteplimit;
    Graph *G;
    PIBT_Agents A;
    std::vector<Task*> T_OPEN;   // open tasks

    std::mt19937* MT;
    std::vector<Task*> T_CLOSE;  // close tasks
  void init();

public:
  MAPF(Graph* _G,
       PIBT_Agents _A,
       std::vector<Task*> _T);
  MAPF(Graph* _G,
       PIBT_Agents _A,
       std::vector<Task*> _T,
       std::mt19937* _MT);
  ~MAPF();
  bool isSolved();
  void update();
  bool allocated() { return true; }

  std::string logStr();
};
