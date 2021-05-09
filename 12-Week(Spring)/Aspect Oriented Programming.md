#### What is AOP
  * AOP is programming paradigm htat aims to increase modularity by allowing the seperation of cross-cutting concerns. 
  * Process of applying external services as transaction management or logging to our application classes without modifying the code.
  * This services are also called cross-cutting concerns.
  * 
#### Terminology
 * ##### Aspect
   * An aspect is a modularization of a concern that cuts across multiple classes. eg- class in which security is implemented
 * ##### Join Point
   * Join point is any point in your program such as method execution, excetion handling, field access, etc. Spring supports only method execution join point.
 * ##### Advice
   * Advice represent an action taken by an aspect at particular join point. types - before / after_mathod_execution
 * ##### Pointcut 
   * It is an expression of AOP that marches join point.
#### OO Way- 
  * define some object and then write getter and setter. it has a problem that lot of similar codes are written.
#### AOP way -
  * getter and setter - it will write getter and setter onn public variable
  * for private variable it will add constructor for that

  * ##### Benefits of AOP
    *  <b> Security </b>
        * Add @security annotationn and add logic elsewhere in aspect security file.
    *  <b> Persistance </b>
    *  <b> Logging </b>
    *  


#### Notes
  * Spring Framework is developed on two core concepts – Dependency Injection and Aspect Oriented Programming ( Spring AOP).
  * We store username and password in property file- 
  * https://docs.spring.io/spring-framework/docs/current/spring-framework-reference/core.html#aop
  * https://www.journaldev.com/2583/spring-aop-example-tutorial-aspect-advice-pointcut-joinpoint-annotations

