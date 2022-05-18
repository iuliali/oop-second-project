# 2WHEELS RENTAL SYSTEM (oop-second-project)

<p align="center"><img src="https://media1.giphy.com/media/1dQ8t83MTSq2q9PkH0/source.gif" width="200" height="200" /> 
    <img src="https://c.tenor.com/C5TeczshWB0AAAAC/maria-tran-bike.gif" width="200" height="200" />
</p>

#UPDATE FOR THIRD OOP PROJECT 
<i>
  <ul>
I've done several updates for the third project:
    <li>added Repository class, which is also a template class - to illustrate REPOSITORY PATTERN</li>
    <li>Rastel and TwoWheelsSystem classes inherit from this Repository class </li>
  </ul>
</i>


# **Short presentation**
<i>
In order to learn and practice both basic and more advanced features of OOP, I created this simple project, which illustrates concepts of: <br>
  <ul>
    <li>encapsulation</li>
    <li>abstraction </li>
    <li>inheritance </li>
    <li>singleton pattern with static data members and functions </li>
    <li>repository pattern</li>
    <li>template class</li>
    <li>exception catching </li>
  </ul>
The program is in Romanian ! (sorry)
</i>

# **Test the functionalities**
<p>My simple program has an interactive menu, with 4 seen options, and 1 unseen option (for the secret menu).</p>
<p>If you run the program you can only see 4 options for all users.</p>

```
1. Rent a bike
2. Give a rent bike back
3. See prices 
4. Exit
```

<p>You can rent ONLY ONE BIKE. In order to take another bike, you have to give the current bike back.</p>

<p>Take your favourite bike from any rack you want, have fun and then return it in any rack.</p>
<p>If you are in the main menu (with the 4 options displayed), you can act as a rental system worker and access the secret menu.</p>

```
Try this path:
1.Inchiriaza bicicleta 
-> choose a rack and then choose a bike that's available in that rack
->2. Returneaza bicicleta
-> see how the bike was added in chosen rack
-> press 5(secret menu)
-> choose a location (rack) and add new bikes in a rack 
-> change prices :))
-> charge all the bikes in a rack (or more)
->(Every time you can insert an inexitent number to check how many exceptions I've caught) 
-GOOD JOB !

``` 

```
5 (invisible - secret menu)
```
<p>In the secret menu, you can add bikes, put bikes to charge (for the electrical ones) and change the current prices</p>


# **What's behind**

<ul> Classes:
<li><b>Menu</b> - singleton - has a pointer to system object</li>
<li><b>TwoWheelsRentalSystem(system)</b> - has a vector of pointers to Rastel objects</li>
<li><b>Rastel</b> - has a vector of pointers to VehiculDouaRoti-derived objects </li>
<li>
<ul><b>VehiculDouaRoti</b> - base abstract class
<li><b>VehiculElectric</b> - derived from VehiculDouaRoti</li>
<li><b>BicicletaStandard</b>- derived from VehiculDouaRoti</li>
<li><b>BicicletaElectrica </b>- derived from VehiculElectric, BicicletaStandard - diamond inheritance</li>
</ul>
</li>
</ul>
<p>I've build the whole project learning and practicing work with pointers. 
Rastel class has a vector with pointers of type VehiculDouaRoti, containing pointers to objects of types derived from VehiculDouaRoti (upcasting).
I've build custom constructors for derived classes and for destructor I've build a virtual destructor for the base class.
I've used static data members for prices in vehicle classes and also for building the Menu, which I've tried to build as a singleton. 
While running  and testing the program, I've found nice opportunities to use try...catch, to throw exceptions in functions and see  how it works.
</p>

<p>When you rent a bike a data member of system class which is of type VehiculDouaRoti*
retains a pointer to an actual bike (BicicletaStandard/ BicicletaElectrica) showing again the upcast concept.
I've also used dynamic_cast in the copy constructor of Rastel to check what type is every bike that should be copied.</p>


# **Written in**
```
Programming language -> C++ 14 
```
