# [Bronze IV] 지폐 세기 - 30031 

[문제 링크](https://www.acmicpc.net/problem/30031) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 구현, 사칙연산

### 제출 일자

2025년 7월 18일 12:31:05

### 문제 설명

<p>대한민국 지폐는 천 원권, 오천 원권, 만 원권, 오만 원권으로 총 네 종류가 있다. 각 지폐의 세로 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c38"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>68</mn><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$68\text{mm}$</span></mjx-container>로 모두 같지만, 가로 길이는 모두 다르다. 천 원권의 가로 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c36"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>136</mn><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$136\text{mm}$</span></mjx-container>, 오천 원권의 가로 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>142</mn><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$142\text{mm}$</span></mjx-container>, 만 원권의 가로 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c38"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>148</mn><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$148\text{mm}$</span></mjx-container>, 오만 원권의 가로 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>154</mn><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$154\text{mm}$</span></mjx-container>이다. 따라서 가로의 길이를 통해서 지폐의 종류를 구분할 수 있다.</p>

<p>수민이는 대한민국 지폐 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>장을 가지고 있다. 수민이는 종이의 크기를 재는 기계를 이용하여 각 지폐의 가로, 세로 길이를 알아냈다. 수민이가 가진 지폐의 총액을 구해보자.</p>

### 입력 

 <p>첫째 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N(1\leq N\leq 100)$</span></mjx-container>이 주어진다.</p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 각 지폐의 가로, 세로 길이가 공백으로 구분되어 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mtext>mm</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\text{mm}$</span></mjx-container>단위로 주어진다. 주어지는 지폐의 가로, 세로 길이의 길이는 정수이고 천 원권, 오천 원권, 만 원권, 오만 원권의 가로, 세로 길이 중 하나이다.</p>

### 출력 

 <p>수민이가 가진 지폐의 총액을 출력한다.</p>

