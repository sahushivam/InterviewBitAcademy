<h4>Why NOSQL?</h4>
<ol>
	<li>NOSQL is used to make queries faster, as joins are not used in it</li>
	<li>To implement transation properties the MongoDB has mongoose </li>
</ol> 
<h4>Types of NOSQL- </h4>
<ol>
	<li><h4>Key Value Store</h4><ul>
		<li><ol> <h5>Properties</h5>
			<li>The storage of the value as a blob removes the need to index the data to improve performance.
			</li>
			<li> The relationship between data does not have to be calculated by a query language; there is no optimization performed. So they are used as cache </li>
			</ol></li>
		<li><ol> <h5>Use Case -</h5>
			<li>Session management at high scale </li>
			<li><b> User preference and profile stores </b> </li>
			<li> Ad servicing; customer shopping habits result in customized ads, coupons, etc. for each customer in real-time </li>
			<li><b> Can effectively work as a cache for heavily accessed but rarely updated data</b> </li>
			</ol></li>
		<li><ol>
			<h5>Examples</h5>
			<li> Redis </li>
			</ol></li></ul>
	</li>
	<li><h4>Document Store</h4>
		<ol> <h5>Properties</h5>
			<li>associate keys with a complex data schema known as a document. Nested documents and key-array/value pairs are containable inside each document.
			</li>
		</ol>
		<ol><h5> Use Case -</h5>
		</ol>
		<ol>
			Examples <ol>
			<li> MongoDB </li> </ol>
		</ol>
	</li>
	<li>
		<h4>Wide Column Store</h4>
		<ol><h5> Properties </h5>
			<li>NoSQL model stores that in columns rather than rows. Thus, it’s perfect for queries and less than optimal for large sets of data.</li>
			<li><b>Advantages</b>Columnar databases store each column in a separate file. Columnar relational models allow for improved compression of attributes when stored in an attribute-wise manner. All of the data in each file is of the same data file.
		</li>
		<li>
			<b>Disadvantages </b> updates can be inefficient.
		</li>	
	</ol>
	</li>
	<li><h4>GraphDB</h4></li>
	</ol>
<h4>Notes</h4>
<ol>
	<li>
		While querying n/2 shards, whichever shard has latest data, i.e decided by versioning it returns that data. So it is not election based rather it is versioning.
	</li>
	<li>
		Range query in distributed DB - 
	</li>
</ol>
