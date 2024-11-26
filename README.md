<body>
<div class="Div2"><i><b>README</b></i></div><br><center><img src ="logo.jpg" width=250 height=100></center>
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
<a href="#roundout" style="margin-left:80px;">roundout</a>
<br>
<a href="#roundin" style="margin-left:80px;">roundin</a>
<br>
<a href="#randint" style="margin-left:80px;">randint</a>
<br>
<a href="#logn" style="margin-left:80px;">logn</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">String to int, float, double</li></b>
<a href="#si" style="margin-left:80px;">si</a>
<br>
<a href="#sf" style="margin-left:80px;">sf</a>
<br>
<a href="#sf2" style="margin-left:80px;">sf2</a>
<br>
<a href="#stod" style="margin-left:80px;">stod</a>
<br>
<b><li style="margin-left:40px; color: #2c4786;">On std::vector&lt;Type&gt;</li></b>
<b><li style="margin-left:60px; color: #2c4786;">Statistical functions</li></b>
<a href="#sum" style="margin-left:80px;">sum</a>
<br>
<a href="#Mean" style="margin-left:80px;">Mean</a>
<br>
<a href="#quantile" style="margin-left:80px;">quantile</a>
<br>
<a href="#quantile_theoretical" style="margin-left:80px;">quantile_theoretical</a>
<br>
<a href="#med" style="margin-left:80px;">med</a>
<br>
<a href="#cor" style="margin-left:80px;">cor</a>
<br>
<a href="#Sd" style="margin-left:80px;">Sd</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Uniform distribution</li></b>
<a href="#unif" style="margin-left:100px;">unif</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Normal distribution</li></b>
<a href="#norm" style="margin-left:100px;">norm</a>
<br>
<a href="#norm2 " style="margin-left:100px;">norm2 </a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Min - Max</li></b>
<a href="#min" style="margin-left:80px;">min</a>
<br>
<a href="#max" style="margin-left:80px;">max</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Mixing </li></b>
<b><li style="margin-left:80px; color: #2c4786;">Heuristic (slightly slower)</li></b>
<a href="#mixout" style="margin-left:100px;">mixout</a>
<br>
<a href="#mixin" style="margin-left:100px;">mixin</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Deterministic (slightly faster)</li></b>
<a href="#mixoutd" style="margin-left:100px;">mixoutd</a>
<br>
<a href="#mixind" style="margin-left:100px;">mixind</a>
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
<b><li style="margin-left:60px; color: #2c4786;">Remove range of elements</li></b>
<a href="#rm_ordered" style="margin-left:80px;">rm_ordered</a>
<br>
<a href="#rm_unordered" style="margin-left:80px;">rm_unordered</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Sets (Union - Diff - Removing shared elements)</li></b>
<a href="#union2" style="margin-left:80px;">union2</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Variadic / Indefinite number of arguments - Unionv Class</li></b>
<a href="#Unionv.to_union()" style="margin-left:100px;">Unionv.to_union()</a>
<br>
<a href="#intersect2" style="margin-left:80px;">intersect2</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Variadic / Indefinite number of arguments - Intersectv Class</li></b>
<a href="#Intersectv.to_intersect() " style="margin-left:100px;">Intersectv.to_intersect() </a>
<br>
<a href="#diff2" style="margin-left:80px;">diff2</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Variadic / Indefinite number of arguments - Diffv Class</li></b>
<a href="#Diffv.to_diff()" style="margin-left:100px;">Diffv.to_diff()</a>
<br>
<a href="#rm_shared_in" style="margin-left:80px;">rm_shared_in</a>
<br>
<a href="#rm_shared_out" style="margin-left:80px;">rm_shared_out</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Variadic / Indefinite number of arguments - Rm_sharedv Class</li></b>
<a href="#Rm_sharedv.to_rm()" style="margin-left:100px;">Rm_sharedv.to_rm()</a>
<br>
<b><li style="margin-left:60px; color: #2c4786;">Others</li></b>
<a href="#pct_to_idx" style="margin-left:80px;">pct_to_idx</a>
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
<b><li style="margin-left:40px; color: #2c4786;">Statistical distributions</li></b>
<b><li style="margin-left:60px; color: #2c4786;">Normal distribution</li></b>
<b><li style="margin-left:80px; color: #2c4786;">Getting probability from values</li></b>
<a href="#normal_ppoint" style="margin-left:100px;">normal_ppoint</a>
<br>
<a href="#normal_prange" style="margin-left:100px;">normal_prange</a>
<br>
<b><li style="margin-left:80px; color: #2c4786;">Getting values from probability</li></b>
<a href="#normal_offval" style="margin-left:100px;">normal_offval</a>
<br>
<b><li style="margin-left:20px; color: #2c4786;">Fulgurance Tools</li></b>
<a href="#Parser_tokenizer_full" style="margin-left:40px;">Parser_tokenizer_full</a>
<br>
</ul><br>
</div>
</div>
<div class="box2">
<br><hr><h1 style="color: #2c4786;"><b id="INTRODUCTION">INTRODUCTION:</b></h1>
<p>Stylished documentation is available <a href="https://julienlargetpiet.tech/static/files/fulgurance.html">here</a></p><p>In current development.</p><p>This framework provides functions for statistical analysis, machine learning, parsing and data manipulation with its own implementation of matrices and dataframes. Other tools can be found at fulgurance_tools part.</p><p>The framework is developped with C++ 14 but should work properly with 11 and 17 and furthers.</p><p>The main branch provides algorithms developped on the top of stl vector, but a deque version is coming.</p><h2 style="color: #2c4786;">Philosophy</h2><p>Matrices and dataframes implementation are classes. All functions that will transform 'voidly' (internaly) the relative data are built in the classes. All functions that copy and transform the relative data are extern to classes.</p><p>Also, all the functions relative to matrices classes exist for more standard type of matrices that is stl 2D vectors.</p><br>
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
<h2 id="roundout" style="test-align: left;">roundout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T roundout(T &x, int &n)</code></div>
<h3>#Description</h3>
<p>Returns a rounded value with decimal precision.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an int, float, double</th></tr>
<tr><th>n </th><th> is an int indicating the decimal precision</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>float x = 34.476;</code>
<br><code>int n = 2;</code>
<br><code>float out = roundout(x, n);</code>
<br><code>34.48</code>
<br><code>n = 0;</code>
<br><code>out = roundout(x, n);</code>
<br><code>34</code>
<br><code>n = -1;</code>
<br><code>out = roundout(x, n)</code>
<br><code>30</code>
</div>
<br>
<hr class="hr">
<h2 id="roundin" style="test-align: left;">roundin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void roundin(T &x, int &n)</code></div>
<h3>#Description</h3>
<p>Transforms the input value to a rounded value with decimal precision.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an int, float, double</th></tr>
<tr><th>n </th><th> is an int indicating the decimal precision</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>float x = 34.476</code>
<br><code>int n = 2;</code>
<br><code>roundin(x, n);</code>
<br><code>34.48</code>
<br><code>n = 0;</code>
<br><code>x = 67.754;</code>
<br><code>roundin(x, n);</code>
<br><code>68</code>
<br><code>n = -1;</code>
<br><code>roundin(x, n);</code>
<br><code>70</code>
</div>
<br>
<hr class="hr">
<h2 id="randint" style="test-align: left;">randint</h2>
<h3>#Usage</h3>
<div class="Div"><code>auto randint(const int &min, const int max, int seed = -1)</code></div>
<h3>#Description</h3>
<p>Returns a pseudo-random number between min and max.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
min </th><th> is an int</th></tr>
<tr><th>max </th><th> is a max</th></tr>
<tr><th>seed </th><th> is an int that determines the pseudo-random output, defaults to -1, so the seed will be randomly picked up by default, if you want to determine the output, choose a seed between 0 and 9.</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>int min = -300;</code>
<br><code>int max = 100;</code>
<br><code>randint(min, max);</code>
<br><code>-14</code>
<br><code>randint(min, max);</code>
<br><code>-231</code>
<br><code>// If you want to generate a float just do:</code>
<br><code>double x = randint(min, max);</code>
<br><code>min = 0;</code>
<br><code>max = 900;</code>
<br><code>x += randint() / 1000;</code>
<br><code>-13.257</code>
</div>
<br>
<hr class="hr">
<h2 id="logn" style="test-align: left;">logn</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; double logn(T &val, T2 &base) </code></div>
<h3>#Description</h3>
<p>Returns the logarithm of any positive number to any base. This generalizes the <code>log(value) / log(base)</code> method.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
val </th><th> is the value of the logarith base n (must be positive)</th></tr>
<tr><th>base </th><th> is the base of the logarithm</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>double val = 2.63;</code>
<br><code>int base = 10;</code>
<br><code>logn(val, base);</code>
<br><code>0.419956 </code>
<br><code>base = 2;</code>
<br><code>1.39506 </code>
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
<h2 id="stod" style="test-align: left;">stod</h2>
<h3>#Usage</h3>
<div class="Div"><code>double stod(const std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a converted std::string, that can be converted to a double, to a double.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string a = "4566.132214";</code>
<br><code>double out = stod(a);</code>
<br><code>4566.132214</code>
</div>
<br>
<hr class="hr">
<h2 style="color:#2c4786;">On std::vector&lt;Type&gt;</h2>
<h3 style="color:#2c4786;">Statistical functions</h3>
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
<h2 id="Mean" style="test-align: left;">Mean</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; T Mean(const std::vector&lt;T&gt; &x) </code></div>
<h3>#Description</h3>
<p>Returns the mean of all elements in a vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 4, 2};</code>
<br><code>double out = Mean(vec);</code>
<br><code>2.333333</code>
</div>
<br>
<hr class="hr">
<h2 id="quantile" style="test-align: left;">quantile</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; double quantile(std::vector&lt;T&gt; &x, T2 &prob, double precision = 0.001)</code></div>
<h3>#Description</h3>
<p>Returns the quantile value for a given probability between 0 and 1 for an input stl vector (int, float, double, bool). If you just want to calculate median, the <code>med()</code> function is more straight forward.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool), must be ascendly sorted</th></tr>
<tr><th>prob </th><th> is the probability(float, double)</th></tr>
<tr><th>precision </th><th> is a double value representing the accuracy of the result. The lower the value is, higher the accuracy will be.</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};</code>
<br><code>std::vector&lt;int&gt; vec2 = {1, 2, 3, 4};</code>
<br><code>double prob = 0.89;</code>
<br><code>quantile(vec2, prob);</code>
<br><code>3.67188</code>
<br><code>prob = 0.65;</code>
<br><code>quantile(vec, prob);</code>
<br><code>6.84375 </code>
</div>
<br>
<hr class="hr">
<h2 id="quantile_theoretical" style="test-align: left;">quantile_theoretical</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; double quantile_theoretical(T &mean, T2 &sd, double &val, double offset_prob = 0.05)</code></div>
<h3>#Description</h3>
<p>Returns the quantile value for a given theoretical noral distribution. There is an offset probability input that tells the most offset probability the function has to takein count in order to return the quantile value.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
mean </th><th> is the mean of the normal distribution</th></tr>
<tr><th>sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>val </th><th> is the quantile percentage (between 0 and 1)</th></tr>
<tr><th>offset_prob </th><th> is the probability from which is no longer not taken in count by the function in order to return a coherent value</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code></code>
<br><code>double val = 0.65;</code>
<br><code>double offset_prob = 0.05;</code>
<br><code>int mean = 144;</code>
<br><code>int sd = 2;</code>
<br><code>double out = quantile_theoretical(mean, sd, val, offset_prob);</code>
<br><code>144.998</code>
</div>
<br>
<hr class="hr">
<h2 id="med" style="test-align: left;">med</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; double med(std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns the median of a stl vector (int, float, double, bool). </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double, bool), must be ascendly sorted</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 2, 3, 4};</code>
<br><code>double out = med(vec);</code>
<br><code>2.5</code>
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
<h2 id="Sd" style="test-align: left;">Sd</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; double Sd(std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns the standard deviation of a stl vector (int, float, double, bool).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector (int, float, double, bool)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {1, 2, 2, 3, 3, 3, 4, 4, 5};</code>
<br><code>double out = Sd(vec);</code>
<br><code>1.224745</code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Uniform distribution</h4>
<h2 id="unif" style="test-align: left;">unif</h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector&lt;double&gt; unif(unsigned int &n, double &min, double &max, double noise = 0.1, int seed = -1)</code></div>
<h3>#Description</h3>
<p>Returns a stl double vector containing pseudo-random uniform distribution between a min and max.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
n </th><th> is the number of elements of the output stl vector</th></tr>
<tr><th>min </th><th> is the minimum of the uniform distribution</th></tr>
<tr><th>max </th><th> is the maximum of the uniform distribution</th></tr>
<tr><th>noise </th><th> is the noise in the returnde uniform distribution </th></tr>
<tr><th>seed </th><th> is an int, controlling the output values, defaults to -1, so by default the function returns pseudo-random uniform distribution. If you want to manually control the output, enter a positive int for this parameter.</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>unsigned int n = 1500;</code>
<br><code>double min = 1;</code>
<br><code>double max = 55;</code>
<br><code>std::vector&lt;double&gt; out = unif(n, min, max);</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 1  1.03701  1.07557  1.10951  1.14757  1.18151  1.21957  1.25351  1.29157  1.32551  1.36357  1.39751  1.43557  1.46951  1.50757  1.54151  1.57957  1.61351  1.65157  1.68551  1.72357  1.75751  1.79557  1.82951  </code>
<br><code>...</code>
<br><code>:1475: 54.1015 54.1396 54.1735 54.2116 54.2455 54.2836 54.3175 54.3556 54.3895 54.4276 54.4615 54.4996 54.5335 54.5716 54.6055 54.6436 54.6775 54.7156 54.7495 54.7876 54.8215 54.8596 54.8935 54.9316 </code>
<br><code>:1500: 55</code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Normal distribution</h4>
<h2 id="norm" style="test-align: left;">norm</h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector&lt;double&gt; norm(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1) </code></div>
<h3>#Description</h3>
<p>Returns a pseudo-random normal distribution as a double stl vector. Note, if you can it is preferable to choose the smallest standard deviation possible to increase speed. Example: N(14, 10) -&gt; N(1.4, 1).</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
n </th><th> is the number of elements in the output stl vector</th></tr>
<tr><th>mean </th><th> is the mean of the normal distribution</th></tr>
<tr><th>sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>noise </th><th> is the noise, defaults to 0.05</th></tr>
<tr><th>seed </th><th> is an int that dictates the result, defaults to -1, so by default the output is pseudo-random</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>unsigned int n = 10000;</code>
<br><code>double sd = 250;</code>
<br><code>double mean = 155;</code>
<br><code>std::vector&lt;double&gt; sd_vec;</code>
<br><code>std::vector&lt;double&gt; out;</code>
<br><code>double result;</code>
<br><code>out = norm(n, mean, sd);</code>
<br><code>Sd(out);</code>
<br><code>250.6228</code>
<br><code>Mean(out);</code>
<br><code>154.9945</code>
<br>
<img style="margin-left: 20px;" height="220" width="360" src="example.jpg"><br></div>
<br>
<hr class="hr">
<h2 id="norm2 " style="test-align: left;">norm2 </h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector&lt;double&gt; norm2(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1)</code></div>
<h3>#Description</h3>
<p>Same as <code>norm()</code>, but faster and less accurate.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
n </th><th> is the number of elements in the output stl vector</th></tr>
<tr><th>mean </th><th> is the mean of the normal distribution</th></tr>
<tr><th>sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>noise </th><th> is the noise, defaults to 0.05</th></tr>
<tr><th>seed </th><th> is an int that dictates the result, defaults to -1, so by default the output is pseudo-random</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>unsigned int n = 10000;</code>
<br><code>double sd = 50;</code>
<br><code>double mean = 155;</code>
<br><code>std::vector&lt;double&gt; sd_vec;</code>
<br><code>std::vector&lt;double&gt; out;</code>
<br><code>double result;</code>
<br><code>out = norm2(n, mean, sd);</code>
<br><code>Sd(out);</code>
<br><code>42.06729</code>
<br><code>Mean(out);</code>
<br><code>155.0009</code>
<br>
<img style="margin-left: 20px;" height="220" width="360" src="example2.jpg"><br></div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Min - Max</h3>
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
<h3 style="color:#2c4786;">Mixing </h3>
<h4 style="color:#2c4786;">Heuristic (slightly slower)</h4>
<h2 id="mixout" style="test-align: left;">mixout</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void mixout(std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Returns a stl vector with its elements at different indexes pseudo-randomly chosen.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector of any type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec;</code>
<br><code>for (int i = 0; i &lt; 100; ++i) {</code>
<br><code>  vec.push_back(i);</code>
<br><code>};</code>
<br><code>std::vector&lt;int&gt; out = mixout(vec);</code>
<br><code>print_nvec(out);</code>
<br><code>  :0: 66 10 51 47 46 57 13 6  85 40 28 55 42 91 61 34 63 12 23 19 79 62 35 84 </code>
<br><code> :25: 43 5  54 17 93 90 0  73 9  18 49 71 20 89 70 41 4  56 22 45 2  29 88 31 </code>
<br><code> :50: 65 3  75 25 94 77 52 78 39 87 83 27 1  15 24 44 76 99 58 95 92 68 97 26 </code>
<br><code> :75: 64 74 11 80 81 69 59 38 8  7  50 14 98 36 82 60 72 32 96 33 37 30 53 67 </code>
<br><code>:100: 48</code>
</div>
<br>
<hr class="hr">
<h2 id="mixin" style="test-align: left;">mixin</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void mixin(std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Transforms a stl vector with its elements at different indexes pseudo-randomly chosen.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector of any type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec;</code>
<br><code>for (int i = 0; i &lt; 100; ++i) {</code>
<br><code>  vec.push_back(i);</code>
<br><code>};</code>
<br><code>mixin(vec);</code>
<br><code>print_nvec(vec);</code>
<br><code>  :0: 66 10 51 47 46 57 13 6  85 40 28 55 42 91 61 34 63 12 23 19 79 62 35 84 </code>
<br><code> :25: 43 5  54 17 93 90 0  73 9  18 49 71 20 89 70 41 4  56 22 45 2  29 88 31 </code>
<br><code> :50: 65 3  75 25 94 77 52 78 39 87 83 27 1  15 24 44 76 99 58 95 92 68 97 26 </code>
<br><code> :75: 64 74 11 80 81 69 59 38 8  7  50 14 98 36 82 60 72 32 96 33 37 30 53 67 </code>
<br><code>:100: 48</code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Deterministic (slightly faster)</h4>
<h2 id="mixoutd" style="test-align: left;">mixoutd</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; mixoutd(std::vector&lt;T&gt; x)</code></div>
<h3>#Description</h3>
<p>Returns a stl vector with its elements at different indexes. The function is determinitic based on the size of the input stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector of any type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec;</code>
<br><code>for (int i = 0; i &lt; 100; ++i) {</code>
<br><code>  vec.push_back(i);</code>
<br><code>};</code>
<br><code>std::vector&lt;int&gt; out = mixoutd(vec);</code>
<br><code>print_nvec(out);</code>
<br><code>  :0: 93 65 90 45 1  41 51 79 28 13 18 84 68 37 77 22 15 29 44 9  6  47 36 57 </code>
<br><code> :25: 14 24 26 46 56 96 33 61 54 59 5  73 34 76 75 71 11 78 92 31 48 50 55 49 </code>
<br><code> :50: 52 17 89 21 0  81 64 82 39 67 53 40 63 66 83 97 99 42 2  86 85 80 60 72 </code>
<br><code> :75: 20 87 27 4  35 19 10 88 43 98 38 8  30 69 58 23 16 95 32 94 91 70 74 62 </code>
<br><code>:100: 25</code>
</div>
<br>
<hr class="hr">
<h2 id="mixind" style="test-align: left;">mixind</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; mixind(std::vector&lt;T&gt; &x)</code></div>
<h3>#Description</h3>
<p>Transforms a stl vector with its elements at different indexes. The function is determinitic based on the size of the input stl vector.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector of any type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec;</code>
<br><code>for (int i = 0; i < 100; ++i) {</code>
<br><code>  vec.push_back(i);</code>
<br><code>};</code>
<br><code>mixind(vec);</code>
<br><code>print_nvec(vec);</code>
<br><code>  :0: 93 65 90 45 1  41 51 79 28 13 18 84 68 37 77 22 15 29 44 9  6  47 36 57 </code>
<br><code> :25: 14 24 26 46 56 96 33 61 54 59 5  73 34 76 75 71 11 78 92 31 48 50 55 49 </code>
<br><code> :50: 52 17 89 21 0  81 64 82 39 67 53 40 63 66 83 97 99 42 2  86 85 80 60 72 </code>
<br><code> :75: 20 87 27 4  35 19 10 88 43 98 38 8  30 69 58 23 16 95 32 94 91 70 74 62 </code>
<br><code>:100: 25</code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Print</h3>
<h2 id="print_nvec" style="test-align: left;">print_nvec</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x, int untl = -1) </code></div>
<h3>#Description</h3>
<p>Print a stl vector (int, float, double, bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool)</th></tr>
<tr><th>untl </th><th> is an int idicating how many elements must be printed, defaults to -1, so by default all elements will be printed</th></tr>
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
<div class="Div"><code>template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x, int untl = -1) </code></div>
<h3>#Description</h3>
<p>Print a stl vector (int, float, double, bool)</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> stl vector (int, float, double, bool)</th></tr>
<tr><th>untl </th><th> is an int idicating how many elements must be printed, defaults to -1, so by default all elements will be printed</th></tr>
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
<p>Returns a boolean vector of 2 stl vectors that will be compared elements by elements. The vectors should not necessarily be the same size. The output boolean vector will be the same size as the first stl vector argument. This is the prefered way when there are only 2 vectors to compare, compared to using Compv class.</p>
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
<h3 style="color:#2c4786;">Remove range of elements</h3>
<h2 id="rm_ordered" style="test-align: left;">rm_ordered</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void rm_ordered(std::vector&lt;T&gt; &x, std::vector&lt;int&gt; ids)</code></div>
<h3>#Description</h3>
<p>Remove elements from a stl vector. Keeps the vector sorted at a certain computational cost compared to <a href="#rm_unordered">rm_unordered</a>. The stl int vector provided for the indices of the element to be removed must be decreasingly sorted. The capacity of the vector is kept unchanged, so if you want to shrink it, consider doing <code>shrink_to_fit()</code> method.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>ids </th><th> is an stl int vector decreasingly sorted</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};</code>
<br><code>std::vector&lt;int&gt; ids = {8, 5, 3, 2};</code>
<br><code>rm_ordered(vec, ids); </code>
<br><code>print_nvec(vec);</code>
<br><code>:0: 0 1 4 6 7 9</code>
</div>
<br>
<hr class="hr">
<h2 id="rm_unordered" style="test-align: left;">rm_unordered</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void rm_unordered(std::vector&lt;T&gt; &x, std::vector&lt;int&gt; ids) </code></div>
<h3>#Description</h3>
<p>Remove elements from a stl vector. Does not keep the vector sorted for computational speed compared to <a href="#rm_ordered">rm_ordered</a>. The stl int vector provided for the indices of the element to be removed must be decreasingly sorted. The capacity of the vector is kept unchanged, so if you want to shrink it, consider doing <code>shrink_to_fit()</code> method.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>ids </th><th> is an stl int vector decreasingly sorted</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};</code>
<br><code>std::vector&lt;int&gt; ids = {8, 5, 3, 2};</code>
<br><code>rm_unordered(vec, ids); </code>
<br><code>print_nvec(vec);</code>
<br><code>:0: 0 1 6 7 4 9 </code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Sets (Union - Diff - Removing shared elements)</h3>
<h2 id="union2" style="test-align: left;">union2</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; union2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Returns the union of two stl vectors. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>x2 </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};</code>
<br><code>std::vector&lt;int&gt; out = union2(vec1, vec2);</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 3  4  4  5  7  8  2  4  0  1  2  3  9  11 </code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Variadic / Indefinite number of arguments - Unionv Class</h4>
<h2 id="Unionv.to_union()" style="test-align: left;">Unionv.to_union()</h2>
<h3>#Usage</h3>
<div class="Div"><code>Unionv union1(std::vector&lt;Type&gt; vec1);<br>union1.to_union(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);<br>union1.result();<br>union1.reinitiate(std::vector&lt;Type2&gt; vec4);<br>...</code></div>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
... </th><th> undefinite number of stl vector of the same type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};</code>
<br><code>std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};</code>
<br><code>Unionv union1(vec1);</code>
<br><code>union1.to_union(vec2, vec3, vec3);</code>
<br><code>std::vector&lt;int&gt; out = union1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 3  4  4  5  7  8  2  4  11 0  1  2  3  9  11 4  0  1  2  3  11 9  0  1  </code>
<br><code>union1.reinitiate(vec2);</code>
<br><code>union1.to_union(vec1);</code>
<br><code>out = union1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 0  1  2  3  9  11 4  3  4  4  5  7  8  2  4  11 </code>
</div>
<br>
<hr class="hr">
<h2 id="intersect2" style="test-align: left;">intersect2</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; union2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Returns the commun elements of two stl vectors of the same type. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>x2 </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};</code>
<br><code>std::vector&lt;int&gt; out = intersect2(vec1, vec2);</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 2 3 </code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Variadic / Indefinite number of arguments - Intersectv Class</h4>
<h2 id="Intersectv.to_intersect() " style="test-align: left;">Intersectv.to_intersect() </h2>
<h3>#Usage</h3>
<div class="Div"><code>Intersectv intersect1(std::vector&lt;Type&gt; vec1);<br>intersect1.to_intersect(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);<br>intersect1.reinitiate(std::vector&lt;Type2&gt;);<br>...</code></div>
<h3>#Description</h3>
<p>Returns the commun elements of undefinite number of stl vectors of the same type. The returned vector can have extra capacity non initiated, to get rid of that consider applying it the <code>shrink_to_fit()</code> method. The returned vector does not return unique elements, so if you want unique elements, consider enter unique stl vectors as input.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
... </th><th> undefinite number of stl vectors</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};</code>
<br><code>std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};</code>
<br><code>Intersectv intersect1(vec1);</code>
<br><code>intersect1.to_intersect(vec2, vec3);</code>
<br><code>std::vector&lt;int&gt; out = intersect1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 3  2  11 </code>
<br><code>intersect1.reinitiate(vec1);</code>
<br><code>intersect1.to_intersect(vec2);</code>
<br><code>out = intersect1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 3  4  4  2  4  11</code>
</div>
<br>
<hr class="hr">
<h2 id="diff2" style="test-align: left;">diff2</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; diff2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Returns the elements that are in one of the stl vector but not in the intersection of all stl vectors. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>x2 </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};</code>
<br><code>std::vector&lt;int&gt; out = diff2(vec1, vec2);</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 9  4  4  5  7  8  11 4  0  1  </code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Variadic / Indefinite number of arguments - Diffv Class</h4>
<h2 id="Diffv.to_diff()" style="test-align: left;">Diffv.to_diff()</h2>
<h3>#Usage</h3>
<div class="Div"><code>Diffv diff1(std::vector&lt;Type&gt; vec1)<br>diff1.to_diff(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec2);<br>diff1.result();<br>diff1.reinitiate(std::vector&lt;Type2&gt; vec4);<br>...</code></div>
<h3>#Description</h3>
<p>Returs a stl vector of all the elements that are in one of the undefinite number of input stl vectors (of the same type) or more, but not in the intersection of all these stl vectors. Does not return a stl vector with unique elements, if you want it to return a stl vector with unique elements make sure that your input vectors contain unique elements. The returned vector can have more capacity than its size, to get rid of this unusable memory, you can apply the <code>shrink_to_fit()</code> method on it.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
... </th><th> undefinite number of stl vectors of the same type</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};</code>
<br><code>std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};</code>
<br><code>Diffv diff1(vec1);</code>
<br><code>diff1.to_diff(vec2, vec3);</code>
<br><code>std::vector&lt;int&gt; out = diff1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 9 4 4 5 7 8 9 4 4 0 1 0 1 </code>
<br><code>diff1.reinitiate(vec3);</code>
<br><code>diff1.to_diff(vec2, vec1);</code>
<br><code>out = diff1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 0 1 4 4 4 9 0 1 5 7 9 8 4 //same elements, different orders because the initializer vector is not the same </code>
</div>
<br>
<hr class="hr">
<h2 id="rm_shared_in" style="test-align: left;">rm_shared_in</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; void rm_shared_in(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Transforms the first stl vector input removing its commun elements with the second stl vector of the same type. The returned vector has its capacity unchanged, so consider applying the <code>shrink_to_fit()</code> method to it if you want to free some memory.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>x2 </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};</code>
<br><code>rm_shared_in(vec1, vec2);</code>
<br><code>print_nvec(vec1);</code>
<br><code>:0: 5 7 8 </code>
</div>
<br>
<hr class="hr">
<h2 id="rm_shared_out" style="test-align: left;">rm_shared_out</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T&gt; std::vector&lt;T&gt; rm_shared_out(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)</code></div>
<h3>#Description</h3>
<p>Returns the first stl vector input minus the its commun elements with the second stl vector of the same type. The returned vector has its capacity unchanged, so consider applying the <code>shrink_to_fit()</code> method to it if you want to free some memory.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is an stl vector</th></tr>
<tr><th>x2 </th><th> is an stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};</code>
<br><code>std::vector&lt;int&gt; out = rm_shared_out(vec1, vec2);</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 5 7 8 </code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Variadic / Indefinite number of arguments - Rm_sharedv Class</h4>
<h2 id="Rm_sharedv.to_rm()" style="test-align: left;">Rm_sharedv.to_rm()</h2>
<h3>#Usage</h3>
<div class="Div"><code>Rm_sharedv rm1(std::vector&lt;Type&gt; vec1);<br>rm1.to_comp(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);<br>rm1.result();<br>rm1.reinitiate(std::vector&lt;OtherType&gt; vec4);<br>...</code></div>
<h3>#Description</h3>
<p>Returns the initializer vector with the shared elements between this vector and an undefinite number of stl vectors, removed. This method is faster than finding commun elements between undefinite number of stl vectors and the initializer vector, and then removing the commun elements.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
... </th><th> undefinite number of stl vectors</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};</code>
<br><code>std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};</code>
<br><code>std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 9, 11, 8};</code>
<br><code>Rm_sharedv obj1(vec1);</code>
<br><code>obj1.to_rm(vec2, vec3);</code>
<br><code>std::vector&lt;int&gt; out = obj1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 4 4 4 5 7 </code>
<br><code>obj1.reinitiate(vec1);</code>
<br><code>out = obj1.result();</code>
<br><code>print_nvec(out);</code>
<br><code>:0: 3 4 4 5 7 8 2 4 </code>
</div>
<br>
<hr class="hr">
<h3 style="color:#2c4786;">Others</h3>
<h2 id="pct_to_idx" style="test-align: left;">pct_to_idx</h2>
<h3>#Usage</h3>
<div class="Div"><code>unsigned int percentage_to_idx(double &val, unsigned int &sizen)</code></div>
<h3>#Description</h3>
<p>Returns an idx of a stl vector from a percentage between 0 and 1.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
val </th><th> is the percentage value, between 0 and 1</th></tr>
<tr><th>sizen </th><th> is the size of the vector you want to have the index.</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::&lt;int&gt; vec = {1, 2, 3, 4};</code>
<br><code>unsigned int sizen = vec.size();</code>
<br><code>double pct = 0.6;</code>
<br><code>unsigned int out = pct_to_idx(pct, sizen);</code>
<br><code>2</code>
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
<div class="Div"><code>template &lt;typename T&gt; void t_in(std::vector&lt;std::vector&lt;T&gt;&gt; &x)</code></div>
<h3>#Description</h3>
<p>Transforms a matrix as 2D stl vector to its transpose</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a matrix as a 2D stl vector</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3, 88, 90}, {4, -5, 6, 78, -7}, {-7, 8, -9, 12, 478}};</code>
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
<h2 style="color:#2c4786;">Statistical distributions</h2>
<h3 style="color:#2c4786;">Normal distribution</h3>
<h4 style="color:#2c4786;">Getting probability from values</h4>
<h2 id="normal_ppoint" style="test-align: left;">normal_ppoint</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2, typename T3&gt; double normal_ppoint(T &mean, T2 &sd, T3 &val)</code></div>
<h3>#Description</h3>
<p>Returns the probability of a value in a normal distribution with given parameters.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
mean </th><th> is the mean of the normal distribution </th></tr>
<tr><th>sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>val </th><th> is the value you want to get its probability</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>double mean = 4;</code>
<br><code>double sdt = 2;</code>
<br><code>double val = 0.65;</code>
<br><code>normal_ppoint(mean, sdt, val);</code>
<br><code>0.176033</code>
</div>
<br>
<hr class="hr">
<h2 id="normal_prange" style="test-align: left;">normal_prange</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2, typename T3, typename T4, typename T5&gt; double normal_prange(T &mean, T2 &sd, T3 &from, T4 &to, T5 &by)</code></div>
<h3>#Description</h3>
<p>Returns the probability of a range of value in a normal distribution with given parameters.</p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
mean </th><th> is the mean of the normal distribution</th></tr>
<tr><th>sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>from is the first value of the range of values</th></tr>
<tr><th>to </th><th> is the last value of the range of values</th></tr>
<tr><th>by </th><th> is the accuracy step of the range of values, the lower it is, higher the result will be accurate</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>double mean = 3;</code>
<br><code>double sd = 1.23;</code>
<br><code>double from = 2;</code>
<br><code>double to = 4;</code>
<br><code>double by = 0.1;</code>
<br><code>double out = normal_prange(mean, sd, from, to, by);</code>
<br><code>0.795199</code>
</div>
<br>
<hr class="hr">
<h4 style="color:#2c4786;">Getting values from probability</h4>
<h2 id="normal_offval" style="test-align: left;">normal_offval</h2>
<h3>#Usage</h3>
<div class="Div"><code>template &lt;typename T, typename T2&gt; double normal_offval(T &sd, T2 prob)</code></div>
<h3>#Description</h3>
<p>Returns the offset value for a given normal distribution with given probability, see example. </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
sd </th><th> is the standard deviation of the normal distribution</th></tr>
<tr><th>offset_prob </th><th> is the offset probability of the wanted value(s)</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>double sdt = 2.33;</code>
<br><code>double offset_prob = 0.001;</code>
<br><code>double out = normal_offval(sdt, prob);</code>
<br><code>mean - out</code>
<br><code>mean - 7.47269 </code>
<br><code>mean + out</code>
<br><code>mean + 7.47269</code>
</div>
<br>
<hr class="hr">
<h1 style="color:#2c4786;">Fulgurance Tools</h1>
<h2 id="Parser_tokenizer_full" style="test-align: left;">Parser_tokenizer_full</h2>
<h3>#Usage</h3>
<div class="Div"><code>std::vector&lt;std::vector&lt;unsigned int&gt;&gt; Parser_tokenizer_full(std::string &x)</code></div>
<h3>#Description</h3>
<p>Returns a 2d stl vectors. First vector is the pair of each parenthesis. Second stl vector is the index of each parenthesis. Takes a stl string as input. </p>
<h3>#Arguments</h3>
<table><tr><th>Name</th><th>Definition</th></tr><tr><th>
x </th><th> is a stl string</th></tr>
</table>
<br>
<h3>#Example(s)</h3>
<div class = "Div"><code>std::string teste = "(o((ldjf)de)po(m()()m)po)()()";</code>
<br><code>std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out = Parser_tokenizer_full(teste);</code>
<br><code>{5 1 0 0 1 4 2 2 3 3 4 5 6 6 7 7}</code>
<br><code>{0 2 3 8 11 14 16 17 18 19 21 24 25 26 27 28}</code>
</div>
<br>
<hr class="hr">
</div>
</div>
</body>
