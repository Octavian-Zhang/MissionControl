/* Code generated for Simulink model codegenReal2Mission */
/* Code generated on Mon Nov 21 19:28:48 2022 */
#include "Executor.hpp"
#include "ModelIO.hpp"

static SendData_IndividualUAVCmd  Arg1{};
static SendData_FCUCMD            Arg2{};
static SendData_FlightLogging     Arg3{};
static RecvData_FlightMode        Arg4{};
static RecvData_RealUAVStateBus   Arg5{};
static RecvData_IndividualUAVCmd  Arg6{};
static SendData_TaskStatus        Arg7{};
static RecvData_NbrUAVStateBus    Arg8{};
static RecvData_VectorSpeed       Arg9{};

static codegenReal2MissionModelClass 
  codegenReal2Mission_Obj{Arg1,Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9};
/* main() handles the following: */
/*  - Instantiate the model object and owns its memory. */
/*  - Call the model initialize and terminate functions. */
/*  - Register tasks and add them to the scheduler */
int main() {

  /* These rate variables represent how many base rate  */
  /* periods to wait before running a step function. */
  double const baserate = 0.1;
  /* Initialize Function */
  codegenReal2Mission_Obj.initialize();
  /* Asynchronous tasks found in the model. */
  /* To schedule these tasks, manually call the functions commented out below:
   */
  /* codegenReal2Mission_PushNbrUAV(); */

  /* Create scheduler and add tasks */
  platform::runtime::Executor executor;
  executor.setBaseRateInSeconds(std::chrono::duration<double>(baserate));
  /* Add periodic tasks */
  executor.addPeriodicEvent([]() { codegenReal2Mission_Obj.step(); }, 1);
  executor.addPeriodicEvent([]() { codegenReal2Mission_Obj.step2(); }, 2);

  /* Run model */
  executor.run();

  /* Terminate Function */
  codegenReal2Mission_Obj.terminate();
  return EXIT_SUCCESS;
}
