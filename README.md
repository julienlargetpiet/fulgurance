<body>
<div class="Div2"><i><b>Documentation</b></i></div><br><center><img src ="logo.jpg" width=250 height=100></center>
<div class="container">
<div class="Divb">
<div class="box1"><a><i>Table Of Contents</i></a><br><br><ul>
<a href="#INTRODUCTION" style="margin-left:0px;">INTRODUCTION</a>
<br>
<b><li style="margin-left:20px; color: #2c4786;">Commun functions  </li></b>
<b><li style="margin-left:40px; color: #2c4786;">On elements</li></b>
<b><li style="margin-left:60px; color: #2c4786;">Standard operations</li></b>
<a href="#mod" style="margin-left:80px;">mod</a>
<br>
<a href="#int_lngth" style="margin-left:80px;">int_lngth</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">String to int, float, double</li></b>
<a href="#si" style="margin-left:80px;">si</a>
<br>
<a href="#sf" style="margin-left:80px;">sf</a>
<br>
<a href="#sf2" style="margin-left:80px;">sf2</a>
<br>
<a href="#sd" style="margin-left:80px;">sd</a>
<br>
<b><li style="margin-left:40px; color: #2c4786;">On std::vector&lt;Type&gt;</li></b>
<b><li style="margin-left:60px; color: #2c4786;">Statisticals functions</li></b>
<a href="#sum" style="margin-left:80px;">sum</a>
<br>
<a href="#mean" style="margin-left:80px;">mean</a>
<br>
<a href="#min" style="margin-left:80px;">min</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Min - Max</li></b>
<a href="#max" style="margin-left:80px;">max</a>
<br>
<a href="#cor" style="margin-left:80px;">cor</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Print</li></b>
<a href="#print_nvec" style="margin-left:80px;">print_nvec</a>
<br>
<a href="#print_svec" style="margin-left:80px;">print_svec</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Absolute values</li></b>
<a href="#abs_vin" style="margin-left:80px;">abs_vin</a>
<br>
<a href="#abs_vout" style="margin-left:80px;">abs_vout</a>
<br>
<a href="#abs_voutb" style="margin-left:80px;">abs_voutb</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Match</li></b>
<a href="#matchl" style="margin-left:80px;">matchl</a>
<br>
<a href="#match" style="margin-left:80px;">match</a>
<br>
<a href="#match_max" style="margin-left:80px;">match_max</a>
<br>
<a href="#match_min" style="margin-left:80px;">match_min</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Grep</li></b>
<a href="#grep" style="margin-left:80px;">grep</a>
<br>
<a href="#grepl" style="margin-left:80px;">grepl</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Unique</li></b>
<a href="#unique" style="margin-left:80px;">unique</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Reverse</li></b>
<a href="#reverse_out" style="margin-left:80px;">reverse_out</a>
<br>
<a href="#reverse_in" style="margin-left:80px;">reverse_in</a>
<br>
<a href="#reverse_out_standard" style="margin-left:80px;">reverse_out_standard</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Repetition of elements</li></b>
<a href="#rep" style="margin-left:80px;">rep</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Sequence/Range of elements</li></b>
<a href="#seq " style="margin-left:80px;">seq </a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Comparisons to booleans </li></b>
<a href="#comp2" style="margin-left:80px;">comp2</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Variadic / Indefinite number of arguments - Compv Class</li></b>
<a href="#Compv.to_comp()" style="margin-left:100px;">Compv.to_comp()</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Any - All</li></b>
<a href="#any" style="margin-left:80px;">any</a>
<br>
<a href="#all" style="margin-left:80px;">all</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Sorting algorithms </li></b>
<a href="#sort_descin" style="margin-left:80px;">sort_descin</a>
<br>
<a href="#sort_ascin" style="margin-left:80px;">sort_ascin</a>
<br>
<a href="#sort_descout" style="margin-left:80px;">sort_descout</a>
<br>
<a href="#sort_ascout" style="margin-left:80px;">sort_ascout</a>
<br>
<b><li style="margin-left:40px; color: #2c4786;">String and vectors conversions</li></b>
<b><li style="margin-left:60px; color: #2c4786;">Collapse (vector to string)</li></b>
<a href="#ncollapse" style="margin-left:80px;">ncollapse</a>
<br>
<a href="#scollapse" style="margin-left:80px;">scollapse</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Split (string to vector)</li></b>
<a href="#split" style="margin-left:80px;">split</a>
<br>
<b><li style="margin-left:20px; color: #2c4786;">Operations on matrices like 2d vectors std::vector&lt;std::vector&lt;Type&gt;&gt;</li></b>
<b><li style="margin-left:40px; color: #2c4786;">Transposition</li></b>
<a href="#t" style="margin-left:60px;">t</a>
<br>
<a href="#t_in_square" style="margin-left:60px;">t_in_square</a>
<br>
<a href="#t_in" style="margin-left:60px;">t_in</a>
<br>
<b><li style="margin-left:40px; color: #2c4786;">Print</li></b>
<a href="#print_matr" style="margin-left:60px;">print_matr</a>
<br>
<b><li style="margin-left:40px; color: #2c4786;">Absolute values</li></b>
<a href="#abs_matrin" style="margin-left:60px;">abs_matrin</a>
<br>
<a href="#abs_matrout" style="margin-left:60px;">abs_matrout</a>
<br>
<b><li style="margin-left:20px; color: #2c4786;">Fulgurance Extended</li></b>
<a href="#Parser_tokenizer_full" style="margin-left:40px;">Parser_tokenizer_full</a>
<br>
</ul><br>
</div>
</div>
<div class="box2">
<br><hr><h1 style="color: #2c4786;"><b id="INTRODUCTION">INTRODUCTION:</b></h1>
<p>Stylished documentation is available <a href="https://julienlargetpiet.tech/static/files/fulgurance.html">here</a></p><p>In current development.</p><p>This framework provides functions for statistical analysis, machine learning, parsing and data manipulation with its own implementation of matrices and dataframes. Other tools can be found at fulgurance_extended part.</p><h2 style="color: #2c4786;">Philosophy</h2><p>Matrices and dataframes implementation are classes. All functions that will transform 'voidly' (internaly) the relative data are built in the classes. All functions that copy and transform the relative data are extern to classes.</p><p>Also, all the functions relative to matrices classes exist for more standard type of matrices that is stl 2D vectors.</p><br>
<hr>
<h1 style="color:#2c4786;">Commun functions  </h1>
<h2 style="color:#2c4786;">On elements</h2>
<h3 style="color:#2c4786;">Standard operations</h3>
<h2 id="mod" style="test-align: left;">mod</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; double mod(T &amp;dividend, T &amp;divider)</code></div>
<h3>#Description</h3>
<p>Returns the mod of 2 number (int, float or double)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
a </th><th> is an the dividend (int, float, double)</th></tr>
<tr><th>b </th><th> is the divider (int, float, double)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>float a = 45.216;</code>
<br><code>float b = 3.2164;</code>
<br><code>mod(a, b)</code>
<br><code>0.186401</code>
</div>
<br>
<hr class="hr">
<h2 id="int_lngth" style="test-align: left;">int_lngth</h2>
<h3>#Usage</h3>
<div class="Div"><code>int int_lngth(const int &x)</code></div>
<h3>#Description</h3>
<p>Returns the length of an int.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an int</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>int a = 896;</code>
<br><code>int_lngth(a);</code>
<br><code>3</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">String to int, float, double</h3>
<h2 id="si" style="test-align: left;">si</h2>
<h3>#Usage</h3>
<div class="Div"><code>int si(const std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a std::string that can be converted to an int, to an int.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string that can be converted to an int</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string a = "341";</code>
<br><code>int out = si(a);</code>
<br><code>341</code>
</div>
<br>
<hr class="hr">
<h2 id="sf" style="test-align: left;">sf</h2>
<h3>#Usage</h3>
<div class="Div"><code>float sf(const std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a converted std::string that can be converted to a float, to a float. Produces the same results than <code>stof</code>.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string that can be converted to a float</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string a = "44.23";</code>
<br><code>float out = sf(a);</code>
<br><code>44.23</code>
</div>
<br>
<hr class="hr">
<h2 id="sf2" style="test-align: left;">sf2</h2>
<h3>#Usage</h3>
<div class="Div"><code>float sf2(const std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a converted std::string that can be converted to a float, to a float. Uses another algorithm than <code>edm1_sf</code>.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string that can be converted to a float</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string a = "44.23";</code>
<br><code>float out = sf2(a);</code>
<br><code>44.23</code>
</div>
<br>
<hr class="hr">
<h2 id="sd" style="test-align: left;">sd</h2>
<h3>#Usage</h3>
<div class="Div"><code>double edm1_sd(const std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a converted std::string, that can be converted to a double, to a double.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string a = "4566.132214";</code>
<br><code>double out = sd(a);</code>
<br><code>4566.132214</code>
</div>
<br>
<hr class="hr">
<h2 style="color:#2c4786;">On std::vector&lt;Type&gt;</h2>
<h3 style="color:#2c4786;">Statisticals functions</h3>
<h2 id="sum" style="test-align: left;">sum</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T sum(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns the sum of all elements in a vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;double&gt; vec = {1.434, 22.3322, 32423.097};</code>
<br><code>double out = sum(vec);</code>
<br><code>32446.8632 </code>
</div>
<br>
<hr class="hr">
<h2 id="mean" style="test-align: left;">mean</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T mean(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the mean of all elements in a vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 4, 2};</code>
<br><code>double out = mean(vec);</code>
<br><code>2.333333</code>
</div>
<br>
<hr class="hr">
<h2 id="min" style="test-align: left;">min</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T min(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns the min element from a vector (int, float, double, bool)</p>
<p>For finding the index of the min element refer <a href="#match_min">here</a></p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {4, 1, -7};</code>
<br><code>int out  = min(vec);</code>
<br><code>-7</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Min - Max</h3>
<h2 id="max" style="test-align: left;">max</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T max(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns the max element from a vector (int, float, double, bool)</p>
<p>For finding the index of the min element refer <a href="#match_max">here</a></p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {4, 1, -7};</code>
<br><code>int out  = max(vec);</code>
<br><code>4</code>
</div>
<br>
<hr class="hr">
<h2 id="cor" style="test-align: left;">cor</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; double cor(const std::vector&lt;T&gt; &x, const std::vector&lt;T2&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Returns the correlation between two variables / two stl vectors (int, float, double, bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double, bool)</th></tr>
<tr><th>x2 </th><th> is an stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {1, 2, 3, 4, 5, 6};</code>
<br><code>std::vector&lt;int&gt; vec2 = {-6, -5, -4, -3, -2, -1};</code>
<br><code>double out = cor(vec1, vec2);</code>
<br><code>1</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Print</h3>
<h2 id="print_nvec" style="test-align: left;">print_nvec</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Print a stl vector (int, float, double, bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {12, 2, 4534, 7, -78, 12122};</code>
<br><code>for (int i = 0; i &lt; 20; ++i) { vec.push_back(7); }</code>
<br><code>print_nvec(vec);</code>
<br><code>:0: 12    2     4534  7     -78   12122 23323 12    6     2     8     45    7     7     7     7     7     7     7     7     7     7     7     7     </code>
<br><code>:25: 7     7     7     7     7     7     7     </code>
</div>
<br>
<hr class="hr">
<h2 id="print_svec" style="test-align: left;">print_svec</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Print a stl vector (int, float, double, bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"peugeot", "wolkswagen", "honda", "renault", "stellantis"};</code>
<br><code>for (int i = 0; i &lt; 20; ++i) { vec.push_back("yesss"); }</code>
<br><code>print_svec(vec);</code>
<br><code>:0: peugeot    wolkswagen honda      renault    stellantis yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      </code>
<br><code>:18: yesss      yesss      yesss      yesss      yesss      yesss      yesss       </code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Absolute values</h3>
<h2 id="abs_vin" style="test-align: left;">abs_vin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void abs_vin(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Converts the elements of a vector to absolute values.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, -5, -7, 3};</code>
<br><code>abs_vin(vec);</code>
<br><code>{1, 5, 7, 3}</code>
</div>
<br>
<hr class="hr">
<h2 id="abs_vout" style="test-align: left;">abs_vout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void abs_vout(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the input vector with all of its elements converted to absolute values.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, -5, -7, 3};</code>
<br><code>std::vector&lt;unsigned int&gt; out = abs_vout(vec);</code>
<br><code>{1, 5, 7, 3}</code>
</div>
<br>
<hr class="hr">
<h2 id="abs_voutb" style="test-align: left;">abs_voutb</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; abs_voutb(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the input vector with all of its elements converted to absolute values.</p>
<p>uses another algorithm than <a href="#abs_vout">abs_vout</a>, with indices instead of iterators.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {-45, 23, 21, -6, 45};</code>
<br><code>std::vector&lt;unsigned int&gt; out = abs_voutb(vec);</code>
<br><code>{45, 23, 21, 6, 45}</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Match</h3>
<h2 id="matchl" style="test-align: left;">matchl</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; bool matchl(const std::vector&lt;T&gt; &source, const T2 &ptrn)</code></div>
<h3>#Description</h3>
<p>Returns 1 if the pattern is found in the stl vector, 0 if not. (returns bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
source </th><th> is an stl vector</th></tr>
<tr><th>ptrn </th><th> is the pattern </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};</code>
<br><code>std::string ptrn = "maybe";</code>
<br><code>bool out = matchl(vec, ptrn);</code>
<br><code>1</code>
</div>
<br>
<hr class="hr">
<h2 id="match" style="test-align: left;">match</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; unsigned int match(const std::vector&lt;T&gt; &source, const T2 &ptrn)</code></div>
<h3>#Description</h3>
<p>Returns the index of the pattern in the vector, -1 if not found.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
source </th><th> is an stl vector</th></tr>
<tr><th>ptrn </th><th> is the pattern </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};</code>
<br><code>std::string ptrn = "maybe";</code>
<br><code>unsigned int out = matchl(vec, ptrn);</code>
<br><code>2</code>
</div>
<br>
<hr class="hr">
<h2 id="match_max" style="test-align: left;">match_max</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; unsigned int match_max(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the index of the maximum value in a stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {3, 1, -7, 23, 21};</code>
<br><code>unsigned int out = match_max(vec);</code>
<br><code>3</code>
</div>
<br>
<hr class="hr">
<h2 id="match_min" style="test-align: left;">match_min</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; unsigned int match_min(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the index of the minimum value in a stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {3, 1, -7, 23, 21};</code>
<br><code>unsigned int out = match_min(vec);</code>
<br><code>2</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Grep</h3>
<h2 id="grep" style="test-align: left;">grep</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; std::vector&lt;unsigned int&gt; grep(const std::vector&lt;T&gt; &source, const T2 &ptrn) </code></div>
<h3>#Description</h3>
<p>Returns the indices of a pattern inside a stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
source </th><th> is an stl vector</th></tr>
<tr><th>ptrn </th><th> is the pattern</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};</code>
<br><code>std::string ptrn = "maybe";</code>
<br><code>std::vector&lt;unsigned int&gt; out = grep(vec, ptrn);</code>
<br><code>{3 4}</code>
</div>
<br>
<hr class="hr">
<h2 id="grepl" style="test-align: left;">grepl</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; grepl(const std::vector&lt;T&gt; &source, const T2 &ptrn) </code></div>
<h3>#Description</h3>
<p>Returns a boolean vector where O corresponds to a non match with the pattern andthe corresponding elements of the stl vector. 1 represents a match.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
source </th><th> is an stl vector</th></tr>
<tr><th>ptrn </th><th> is the pattern</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};</code>
<br><code>std::string ptrn = "maybe";</code>
<br><code>std::vector&lt;bool&gt; out = grep(vec, ptrn);</code>
<br><code>{0 0 1 0 1}</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Unique</h3>
<h2 id="unique" style="test-align: left;">unique</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; unique(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns a stl vector with unique elements from an input stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 2, 3, 4, 4, 5, 6, 6};</code>
<br><code>std::vector&lt;int&gt; out = unique(vec);</code>
<br><code>{1, 2, 3, 4, 5, 6}</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Reverse</h3>
<h2 id="reverse_out" style="test-align: left;">reverse_out</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; reverse_out(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns a reverse stl vector from an input stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};</code>
<br><code>std::vector&lt;std::string&gt; out = reverse_out(vec);</code>
<br><code>{"ll", "o", "he"}</code>
</div>
<br>
<hr class="hr">
<h2 id="reverse_in" style="test-align: left;">reverse_in</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; reverse_in(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Reverses a stl vector..</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};</code>
<br><code>reverse_out(vec);</code>
<br><code>{"ll", "o", "he"}</code>
</div>
<br>
<hr class="hr">
<h2 id="reverse_out_standard" style="test-align: left;">reverse_out_standard</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; reverse_out(const std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns a reverse stl vector from an input stl vector. Uses another algorithm than <a href="#reverse_out">reverse_out</a>.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};</code>
<br><code>std::vector&lt;std::string&gt; out = reverse_out(vec);</code>
<br><code>{"ll", "o", "he"}</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Repetition of elements</h3>
<h2 id="rep" style="test-align: left;">rep</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; rep(const std::vector&lt;T&gt; &x, const std::vector&lt;int&gt; &hmn)</code></div>
<h3>#Description</h3>
<p>Returns a stl vector of elements repeted multiple times relatively to an int stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector containing all the elements that will be repeated</th></tr>
<tr><th>hmn </th><th> is a stl int vector containing all the times each element will be repeated </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec;</code>
<br><code>std::vector&lt;int&gt; hmn = {4, 2, 7};</code>
<br><code>std::vector&lt;std::string&gt; elmnts = {"ok", "ko", "ok2"};</code>
<br><code>vec = rep(elmnts, hmn);</code>
<br><code>print_svec(vec);</code>
<br><code>:0: ok  ok  ok  ok  ko  ko  ok2 ok2 ok2 ok2 ok2 ok2 ok2 </code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Sequence/Range of elements</h3>
<h2 id="seq " style="test-align: left;">seq </h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2, typename T3&gt; std::vector&lt;T&gt; seq(T from, T2 const &to, T3 const &by)</code></div>
<h3>#Description</h3>
<p>Returns a stl range vector(int, float, double).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
from </th><th> is the starting value</th></tr>
<tr><th>to </th><th> is the end value</th></tr>
<tr><th>by </th><th> is the step value</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>float from = 1.25; </code>
<br><code>float to = 3;</code>
<br><code>float by = 0.25;</code>
<br><code>std::vector&lt;float&gt; = seq(from, to, by);</code>
<br><code>{1.25, 1.5, 1.75, 2, 1.25, 2.5, 2.75, 3}</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Comparisons to booleans </h3>
<h2 id="comp2" style="test-align: left;">comp2</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; comp2(const std::vector&lt;T&gt; &x, const std::vector&lt;T2&gt; &x2) </code></div>
<h3>#Description</h3>
<p>Returns a boolean vector of 2 stl vectors that will be compared elements by elements. The vectors should not necessarily be the same size. The output boolean vector will be the same size as the first stl vector argument.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector </th></tr>
<tr><th>x2 is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;unsigned int&gt; vec = {1, 5, 2};</code>
<br><code>std::vector&lt;unsigned int&gt; vecb = {1, 5, 22};</code>
<br><code>std::vector&lt;bool&gt; out = comp2(vec, vecb);</code>
<br><code>1 1 0</code>
<br><code>vec = {1, 5, 2, 1, 5, 2};</code>
<br><code>out = comp2(vec, vecb);</code>
<br><code>1 1 0 1 1 0</code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Variadic / Indefinite number of arguments - Compv Class</h4>
<h2 id="Compv.to_comp()" style="test-align: left;">Compv.to_comp()</h2>
<h3>#Usage</h3>
<div class="Div"><code>Compv comp1(std::vector&lt;Type&gt; vec1);<br>comp1.to_comp(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);<br>comp1.result();<br>comp1.reinitiate(std::vector&lt;OtherType&gt; vec4);<br>...</code></div>
<h3>#Description</h3>
<p>Returns a boolean vector of multiple stl vectors that will be compared elements by elements. The vectors do not have necessarily to be the same size. The output boolean vector will be the size of the initiation vector. </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
... </th><th> undefinite number of stl vectors</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;unsigned int&gt; vec = {1, 5, 2};</code>
<br><code>std::vector&lt;unsigned int&gt; vecb = {1, 5, 2};</code>
<br><code>std::vector&lt;unsigned int&gt; vecc = {1, 5, 22};</code>
<br><code>std::vector&lt;unsigned int&gt; vec2 = {1, 5};</code>
<br><code>std::vector&lt;unsigned int&gt; vec2b = {1, 5};</code>
<br><code>std::vector&lt;unsigned int&gt; vec2c = {1, 5};</code>
<br><code>Compv obj1(vec);</code>
<br><code>obj1.to_comp(vecb, vecc);</code>
<br><code>std::vector&lt;bool&gt; out = obj1.result();</code>
<br><code>1 1 0</code>
<br><code>obj1.reinitiate(vec2);</code>
<br><code>out = obj1.result();</code>
<br><code>1 1</code>
<br><code>vec = {1, 5, 22, 1, 5, 2};</code>
<br><code>obj1.reinitiate(vec);</code>
<br><code>obj1.to_comp(vec, vecb, vecc);</code>
<br><code>out = obj1.result();</code>
<br><code>1 1 0 1 1 0</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Any - All</h3>
<h2 id="any" style="test-align: left;">any</h2>
<h3>#Usage</h3>
<div class="Div"><code>bool any(const std::vector&lt;bool&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns 1 if a boolean vector has at least 1 as value of one of its elements, 0 if not.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl boolean vector </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;bool&gt; vec = {0, 0, 1, 0};</code>
<br><code>bool out = any(vec);</code>
<br><code>1</code>
<br><code>std::vector&lt;bool&gt; vec = {0, 0, 0, 0};</code>
<br><code>out = any(vec);</code>
<br><code>0</code>
</div>
<br>
<hr class="hr">
<h2 id="all" style="test-align: left;">all</h2>
<h3>#Usage</h3>
<div class="Div"><code>all any(const std::vector&lt;bool&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns 1 if all the elements of a stl boolean vector equals to 1, 0 if not.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl boolean vector </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;bool&gt; vec = {0, 0, 1, 0};</code>
<br><code>bool out = all(vec);</code>
<br><code>0</code>
<br><code>std::vector&lt;bool&gt; vec = {1, 1, 1, 1};</code>
<br><code>out = all(vec);</code>
<br><code>1</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Sorting algorithms </h3>
<h2 id="sort_descin" style="test-align: left;">sort_descin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void sort_descin(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Transforms a stl vector (int, float, double, bool) to a sorted decreasing stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool) </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};</code>
<br><code>sort_descin(vec);</code>
<br><code>{22, 5, 5, 2, 1, 1}</code>
</div>
<br>
<hr class="hr">
<h2 id="sort_ascin" style="test-align: left;">sort_ascin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void sort_ascin(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Transforms a stl vector (int, float, double, bool) to a sorted increasing stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool) </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};</code>
<br><code>sort_ascin(vec);</code>
<br><code>{1, 1, 2, 5, 5, 22}</code>
</div>
<br>
<hr class="hr">
<h2 id="sort_descout" style="test-align: left;">sort_descout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void sort_descout(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns a stl sorted decreasingly vector from a  stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool) </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};</code>
<br><code>std::&lt;int&gt; out = sort_descout(vec);</code>
<br><code>{22, 5, 5, 2, 1, 1}</code>
</div>
<br>
<hr class="hr">
<h2 id="sort_ascout" style="test-align: left;">sort_ascout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void sort_ascout(std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns a stl sorted increasingly vector from a  stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool) </th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};</code>
<br><code>std::&lt;int&gt; out = sort_ascout(vec);</code>
<br><code>{1, 1, 2, 5, 5, 22}</code>
</div>
<br>
<hr class="hr">
<h2 style="color:#2c4786;">String and vectors conversions</h2>
<h3 style="color:#2c4786;">Collapse (vector to string)</h3>
<h2 id="ncollapse" style="test-align: left;">ncollapse</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; std::string ncollapse(const std::vector&lt;T&gt; &x, const T2 &sep)</code></div>
<h3>#Description</h3>
<p>Collapses all elements from an stl vector (int, float, double, bool) to a string with a given separator.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double, bool)</th></tr>
<tr><th>sep </th><th> is a char or string that will be the separator between the elements of x</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {5, 7, 22, 879};</code>
<br><code>char sep = "-";</code>
<br><code>std::string out = ncollapse(vec, sep);</code>
<br><code>"5-7-22-879"</code>
<br><code></code>
<br><code>std::string sep2 = "--";</code>
<br><code>out = ncollapse(vec, sep2);</code>
<br><code>"5--7--22--879"</code>
</div>
<br>
<hr class="hr">
<h2 id="scollapse" style="test-align: left;">scollapse</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::string scollapse(const std::vector&lt;std::string&gt; &x, const T &sep)</code></div>
<h3>#Description</h3>
<p>Collapses all elements from an stl string vector to a string with a given separator.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (stl string)</th></tr>
<tr><th>sep </th><th> is a char or string that will be the separator between the elements of x</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe"};</code>
<br><code>char sep = "-";</code>
<br><code>std::string out = ncollapse(vec, sep);</code>
<br><code>"yess-no-maybe"</code>
<br><code></code>
<br><code>std::string sep2 = "--";</code>
<br><code>out = ncollapse(vec, sep2);</code>
<br><code>"yess--no--maybe"</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Split (string to vector)</h3>
<h2 id="split" style="test-align: left;">split</h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector&lt;std::string&gt; split(const std::string &x, const char &sep)</code></div>
<h3>#Description</h3>
<p>Returns a stl vector of stl strings that are part of the input stl string. The input string must have a separator to differenciate elements for the output stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string</th></tr>
<tr><th>sep </th><th> is a char</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string test = "y-e-ss";</code>
<br><code>char sep = '-';</code>
<br><code>std::vector&lt;std::string&gt; out = split(test, sep);</code>
<br><code>{"y", "e", "ss"}</code>
</div>
<br>
<hr class="hr">
<h1 style="color:#2c4786;">Operations on matrices like 2d vectors std::vector&lt;std::vector&lt;Type&gt;&gt;</h1>
<h2 style="color:#2c4786;">Transposition</h2>
<h2 id="t" style="test-align: left;">t</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;std::vector&lt;T&gt;&gt; t(const std::vector&lt;std::vector&lt;T&gt;&gt; &x)</code></div>
<h3>#Description</h3>
<p>Retursn the transpose of a matrix as 2D stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a 2D stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}};</code>
<br><code>print_matr(matr); // another function from this library to print matrix as 2D stl vector</code>
<br><code>          [0]       [1]</code>
<br><code>:0:         1         4</code>
<br><code>:1:         2         5</code>
<br><code>:2:         3         6</code>
<br><code>std::vector&lt;std::vector&lt;int&gt;&gt; out = t(matr);</code>
<br><code>print_matr(out);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         2         3</code>
<br><code>:1:         4         5         6</code>
</div>
<br>
<hr class="hr">
<h2 id="t_in_square" style="test-align: left;">t_in_square</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void t_in_square(std::vector&lt;std::vector&lt;T&gt;&gt; &x)</code></div>
<h3>#Description</h3>
<p>Transforms the input <b>square</b> matrix as 2D stl vector (int, float, double, bool) to its transpose.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a 2D stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};</code>
<br><code>print_matr(matr); // another function from this library to print matrix as 2D stl vector</code>
<br><code></code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4         7</code>
<br><code>:1:         2         5         8</code>
<br><code>:2:         3         6         9</code>
<br><code></code>
<br><code>t_in_square(matr);</code>
<br><code></code>
<br><code>print_matr(matr);</code>
<br><code></code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         2         3</code>
<br><code>:1:         4         5         6</code>
<br><code>:2:         7         8         9</code>
</div>
<br>
<hr class="hr">
<h2 id="t_in" style="test-align: left;">t_in</h2>
<h3>#Usage</h3>
<div class="Div"><code>template <typename T> void t_in(std::vector<std::vector<T>> &x)</code></div>
<h3>#Description</h3>
<p>Transforms a matrix as 2D stl vector to its transpose</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a matrix as a 2D stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector<std::vector<int>> matr = {{1, 2, 3, 88, 90}, {4, -5, 6, 78, -7}, {-7, 8, -9, 12, 478}};</code>
<br><code>print_matr(matr);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4        -7</code>
<br><code>:1:         2        -5         8</code>
<br><code>:2:         3         6        -9</code>
<br><code>:3:        88        78        12</code>
<br><code>:4:        90        -7       478</code>
<br><code>t_in(matr);</code>
<br><code>print_matr(matr);</code>
<br><code>          [0]       [1]       [2]       [3]       [4]</code>
<br><code>:0:         1         2         3        88        90</code>
<br><code>:1:         4        -5         6        78        -7</code>
<br><code>:2:        -7         8        -9        12       478</code>
<br><code>t_in(matr);</code>
<br><code>print_matr(matr);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4        -7</code>
<br><code>:1:         2        -5         8</code>
<br><code>:2:         3         6        -9</code>
<br><code>:3:        88        78        12</code>
<br><code>:4:        90        -7       478</code>
</div>
<br>
<hr class="hr">
<h2 style="color:#2c4786;">Print</h2>
<h2 id="print_matr" style="test-align: left;">print_matr</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void print_matr(const std::vector&lt;std::vector&lt;T&gt;&gt; &x) </code></div>
<h3>#Description</h3>
<p>Print a matrix as 2D stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a 2D stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};</code>
<br><code>print_matr(matr);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4         7</code>
<br><code>:1:         2         5         8</code>
<br><code>:2:         3         6         9</code>
</div>
<br>
<hr class="hr">
<h2 style="color:#2c4786;">Absolute values</h2>
<h2 id="abs_matrin" style="test-align: left;">abs_matrin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void abs_matrin(std::vector&lt;std::vector&lt;T&gt;&gt; &x) </code></div>
<h3>#Description</h3>
<p>Transforms all the values of the cells from a matrix as 2D stl vector (int, float, double, bool) to absolute values.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a matrix as 2D stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, -5, 6}, {-7, 8, -9}};</code>
<br><code>print_matr(matr); // another function from this library to print matrix as 2D stl vector</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4        -7</code>
<br><code>:1:         2        -5         8</code>
<br><code>:2:         3         6        -9</code>
<br><code>abs_matrin(matr);</code>
<br><code>print_matr(matr);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4         7</code>
<br><code>:1:         2         5         8</code>
<br><code>:2:         3         6         9</code>
</div>
<br>
<hr class="hr">
<h2 id="abs_matrout" style="test-align: left;">abs_matrout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void abs_matrout(std::vector&lt;std::vector&lt;T&gt;&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns a marix as 2D stl vector (int, float, double, bool) with only absolute values from a matrix as 2D stl vector (int, float, double, bool). </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a matrix as 2D stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, -5, 6}, {-7, 8, -9}};</code>
<br><code>print_matr(matr); // another function from this library to print matrix as 2D stl vector</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4        -7</code>
<br><code>:1:         2        -5         8</code>
<br><code>:2:         3         6        -9</code>
<br><code>std::vector&lt;std::vector&lt;int&gt;&gt; out = abs_matrout(matr);</code>
<br><code>print_matr(out);</code>
<br><code>          [0]       [1]       [2]</code>
<br><code>:0:         1         4         7</code>
<br><code>:1:         2         5         8</code>
<br><code>:2:         3         6         9</code>
</div>
<br>
<hr class="hr">
<h1 style="color:#2c4786;">Fulgurance Extended</h1>
<h2 id="Parser_tokenizer_full" style="test-align: left;">Parser_tokenizer_full</h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector<std::vector<unsigned int>> Parser_tokenizer_full(std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a 2d stl vectors. First vector is the pair of each parenthesis. Second stl vector is the index of each parenthesis. Takes a stl string as input. </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string</th></tr>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string teste = "(o((ldjf)de)po(m()()m)po)()()";</code>
<br><code>std::vector<std::vector<unsigned int>> out = Parser_tokenizer_full(teste);</code>
<br><code>5 1 0 0 1 4 2 2 3 3 4 5 6 6 7 7 </code>
<br><code>0 2 3 8 11 14 16 17 18 19 21 24 25 26 27 28 </code>
</table>
<br>
</div>
</div>
</body>
