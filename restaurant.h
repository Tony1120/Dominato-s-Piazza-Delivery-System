#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namepace std;

#ifndef RESTAURANT_H
#define RESTAURANT_H

      // The Restaurant class keeps track of all drivers and orders in the
      // system, including logged-out drivers and completed orders.
class Restaurant {
public:
  /*
	* Preconditions: None
	* Postcondition: Constructor. Creates a restaurant in an initial state, with
  *                no drivers or orders.
	*/
  Restaurant();

  /*
  * Preconditions: None
  * Postcondition: Prints status of orders and logged-in drivers, as specified
  *                by the “status” command description.
  */
  void status();

  /*
  * Preconditions: None
  * Postcondition: Prints summary statistics on orders and drivers, as specified
  *                by the “summary” command description.
  */
  void summary();

  /*
  * Preconditions: Drive name is passed in as a string
  * Postcondition: If a driver with the given name exists within the system
  *                (logged in or not), returns a pointer to that driver.
  *                Otherwise, returns a null pointer.
  */
  Driver * getDriver(string name);

  /*
  * Preconditions: None
  * Postcondition: Adds the given driver to the system
  */
  void addDriver(Driver* driver);

  /*
  * Preconditions: None
  * Postcondition: Adds the given order to the system, enqueuing it for cooking.
  */
  void addOrder(Order* order);

  /*
  * Preconditions: Cooking queue isnt empty
  * Postcondition: Removes the oldest order from the cooking queue and enqueues
  *                it for departure.
  */
  void serveNextOrder() throw (logic_error);

  /*
  * Preconditions: Departure queue isnt empty
  * Postcondition: Removes the oldest order from the departure queue and returns it.
  */
  Order * departNextOrder() throw (logic_error);

  /*
  * Preconditions: None
  * Postcondition: The order carried by the driver is delivered at the given
  *                time. The driver receives the given tip.
  */
  void deliver(Driver * driver, Time time, float tip);

private:
  list <driver> drivers;
  Queue <order> toCook;
  Queue <order> served;
  list <order> delivered;

};