#### Why singleton is bad?
https://stackoverflow.com/questions/137975/what-is-so-bad-about-singletons/138012#138012

1- Singletons do effectively create a global accessible set of 'stuff'

https://www.journaldev.com/1377/java-singleton-design-pattern-best-practices-examples

#### Use a Singleton if:
    You need to have one and only one object of a type in system
#### Do not use a Singleton if:
<ol>
    <li> You want to save memory </li>
    <li>   You want to try something new </li>
    <li>    You want to show off how much you know </li>
    <li>    Because everyone else is doing it (See cargo cult programmer in wikipedia) </li>
    <li>    In user interface widgets </li>
    <li>    It is supposed to be a cache </li>
    <li>   In strings </li>
    <li>   In Sessions </li>
</ol>

#### How to create the best singleton:
<pre>
  * The smaller, the better. I am a minimalist
  * Make sure it is thread safe
  * Make sure it is never null
  * Make sure it is created only once
  * Lazy or system initialization? Up to your requirements
  * Sometimes the OS or the JVM creates singletons for you (e.g. in Java every class definition is a singleton)
  * Provide a destructor or somehow figure out how to dispose resources
  * Use little memory
</pre>

#### Implementation <ol>
<li>Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.</li>
<li>Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.</li> </ol>

