Install go-tour
The code for go-tour will remain under the directory <go_workspace>/src/code.google.com/p/go-tour/
and the code code go.tools will be under <go_workspace>/src/code.google.com/p/go.tools/

Apply the go_tools.diff from go.tools directory.
Apply the go_tour_changes.diff patch inside go-tour
copy c++.png and put it under go-tour/static directory
clone with cpp-tour contents under go-tour/contents directory

run $go run gotour/tour.go gotour/local.go gotour/fmt.go
from go-tour directory

The c++ tour would appear in the web-brower.

If a static ip-address is specified, anyone from the network cannot connect and run the tour!!

Note:	The connection is a http unsecure connection.. 
	I have not looked into running it in a app-engine with a secure connection yet.

Courtesy: c++.png icon was picked up from www.planet-source-code.com.
	  The go-tour code from golang.org

Have fun!!
