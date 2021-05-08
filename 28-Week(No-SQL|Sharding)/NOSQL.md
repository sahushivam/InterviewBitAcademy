<div>Why NOSQL?</div><ol>
	<li>NOSQL is used to make queries faster, as joins are not used in it</li>
	<li>To implement transation properties the MongoDB has mongoose </li>
			</ol>
Types of NOSQL-
<ol>
	<li>Key Value Store
		<ol> Properties
			<li>The storage of the value as a blob removes the need to index the data to improve performance.
			</li>
			<li> The relationship between data does not have to be calculated by a query language; there is no optimization performed. So they are used as cache </li>
		</ol>
		<ol> Use Case -
			<li>Session management at high scale </li>
			<li><b> User preference and profile stores </b> </li>
			<li> Ad servicing; customer shopping habits result in customized ads, coupons, etc. for each customer in real-time </li>
			<li><b> Can effectively work as a cache for heavily accessed but rarely updated data</b> </li>
		</ol>
		<ol>
			Examples
			<li> Redis </li>
		</ol>
	</li>
	<li>Document Store
		<ol> Properties
			<li>associate keys with a complex data schema known as a document. Nested documents and key-array/value pairs are containable inside each document.
			</li>
		</ol>
		<ol> Use Case -
			
		</ol>
		<ol>
			Examples
			<li> MongoDB </li>
		</ol>
	</li>
	<li>Wide Column Store
	<ol> Properties
			<li>
				NoSQL model stores that in columns rather than rows. Thus, it’s perfect for queries and less than optimal for large sets of data.
			</li>
			<li>
				<b>Advantages</b>Columnar databases store each column in a separate file. Columnar relational models allow for improved compression of attributes when stored in an attribute-wise manner. All of the data in each file is of the same data file.
			</li>
			<li>
			<b>Disadvantages </b>updates can be inefficient.
			</li>
			
		</ol>
	</li>
	<li>GraphDB</li>
	</ol>

Why Document Store vs Sql
<div>
	NodeJS people like it.
	Complex Structure of data
	
	</div>
	
Datatypes in Mongoose
<ul>
	<li>	1- Numerals </li> 
	<li>	2- Boolean </li>
	<li>	3- Array </li>
	<li>	4- Mixed </li> 
	<li>	5- Object </li>
<ul>
Create DB at mongoDB cloud
Connection of MongoDB with express framework
