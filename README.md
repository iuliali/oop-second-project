
# 2WHEELS RENTAL SYSTEM (oop-second-project)

<p align="center"><img src="https://media1.giphy.com/media/1dQ8t83MTSq2q9PkH0/source.gif" width="200" height="200" /> 
    <img src="https://c.tenor.com/C5TeczshWB0AAAAC/maria-tran-bike.gif" width="200" height="200" />
</p>

# **Short presentation**
<i>
In order to learn and practice both basic and more advanced features of OOP, I created this simple project, which illustrates concepts of: <br>
  <ul>
    <li>encapsulation</li>
    <li>abstraction </li>
    <li>inheritance </li>
    <li>singleton pattern with static data members and functions </li>
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
<p> </p>


# **Written in**
```
Programming language -> C++ 14 
```
