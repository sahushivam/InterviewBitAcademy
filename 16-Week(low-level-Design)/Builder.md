Use the Builder pattern when you want your code to be able to create different representations of some product (for example, stone and wooden houses). <br/>
<i>House buildhouse = new House.Builder().setNoOfBedroom(4).setType("Wooden").setFloors(3).build();</i>

#### Pros 
	-> You can construct objects step-by-step, defer construction steps or run steps recursively.
	-> You can reuse the same construction code when building various representations of products.
 	-> Single Responsibility Principle. You can isolate complex construction code from the business logic of the product.

#### Cons
	-> The overall complexity of the code increases since the pattern requires creating multiple new classes.

#### Difference between factory vs Builder
<ol>
	<li> designs start out using Factory Method (less complicated, more customizable, subclasses proliferate) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, more complex) as the designer discovers where more flexibility is needed. </li>
	<li> 1) Builder is mainly used to build POJOs using Fluent API (e.g. Person.builder().withName("Sam").withAge(38).build(). 2) In my experiene, builder is useful for POJO creation for domain objects, whereas factory is useful for creating a service objects like PdfGeneratorFactory class. The service object could be cached within factory for more than 1 time use, whereas builder always creates a new object by design
	    </li>
</ol>

#### Problem without builder Pattern
<ol>	 
	<li> Too many constructors to maintain. </li>
	<li> You can partially solve this problem by creating Pizza and then adding
	ingredients but that will impose another problem of leaving Object on
	inconsistent state during building, ideally cake should not be available until its created.
	Both of these problem can be solved by using Builder design pattern in Java. 
	Builder design pattern not only improves readability but also reduces chance of error by adding ingredients 
	explicitly and making object available ONCE FULLY CONSTRUCTED. </li>
</ol>


~~~java
public class BankAccount {

    public static class Builder {

        private long accountNumber; //This is important, so we'll pass it to the constructor.
        private String owner;
        private String branch;
        private double balance;
        private double interestRate;

        public Builder(long accountNumber) {
            this.accountNumber = accountNumber;
        }

        public Builder withOwner(String owner){
            this.owner = owner;

            return this;  //By returning the builder each time, we can create a fluent interface.
        }

        public Builder atBranch(String branch){
            this.branch = branch;

            return this;
        }

        public Builder openingBalance(double balance){
            this.balance = balance;

            return this;
        }

        public Builder atRate(double interestRate){
            this.interestRate = interestRate;

            return this;
        }

        public BankAccount build(){
            //Here we create the actual bank account object, which is always in a fully initialised state when it's returned.
            BankAccount account = new BankAccount();  //Since the builder is in the BankAccount class, we can invoke its private constructor.
            account.accountNumber = this.accountNumber;
            account.owner = this.owner;
            account.branch = this.branch;
            account.balance = this.balance;
            account.interestRate = this.interestRate;

            return account;
        }
    }

    //Fields omitted for brevity.
    private BankAccount() {
        //Constructor is now private.
    }

    //Getters and setters omitted for brevity.

}
~~~
~~~java
BankAccount account = new BankAccount.Builder(1234L)
            .withOwner("Marge")
            .atBranch("Springfield")
            .openingBalance(100)
            .atRate(2.5)
            .build();
~~~
