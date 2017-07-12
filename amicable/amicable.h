//
//  amicable.h
//  c++
//
//  Created by Aashish Sharma on 9/24/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____amicable__
#define __c____amicable__

#include "../util/util.h"



class amicable {

public:
    
    amicable(int );
    ~amicable();
    
    
private:
    
    void _find_pair(int);
    int _get_sum_of_factors(int num);
    
    int *_factors ;
    void _populate_factors(int);
    
};


#endif /* defined(__c____amicable__) */


#if 0 

0. 220  and 284
1. 1184  and 1210
2. 2620  and 2924
3. 5020  and 5564
4. 6232  and 6368
5. 10744  and 10856
6. 12285  and 14595
7. 17296  and 18416
8. 63020  and 76084
9. 66928  and 66992
10. 67095  and 71145
11. 69615  and 87633
12. 79750  and 88730
13. 100485  and 124155
14. 122265  and 139815
15. 122368  and 123152
16. 141664  and 153176
17. 142310  and 168730
18. 171856  and 176336
19. 176272  and 180848
20. 185368  and 203432
21. 196724  and 202444
22. 280540  and 365084
23. 308620  and 389924
24. 319550  and 430402
25. 356408  and 399592
26. 437456  and 455344
27. 469028  and 486178
28. 503056  and 514736
29. 522405  and 525915
30. 600392  and 669688
31. 609928  and 686072
32. 624184  and 691256
33. 635624  and 712216
34. 643336  and 652664
35. 667964  and 783556
36. 726104  and 796696
37. 802725  and 863835
38. 879712  and 901424
39. 898216  and 980984
40. 947835  and 1125765
41. 998104  and 1043096
42. 1077890  and 1099390
43. 1154450  and 1189150
44. 1156870  and 1292570
45. 1175265  and 1438983
46. 1185376  and 1286744
47. 1280565  and 1340235
48. 1328470  and 1483850
49. 1358595  and 1486845
50. 1392368  and 1464592
51. 1466150  and 1747930
52. 1468324  and 1749212
53. 1511930  and 1598470
54. 1669910  and 2062570
55. 1798875  and 1870245
56. 2082464  and 2090656
57. 2236570  and 2429030
58. 2652728  and 2941672
59. 2723792  and 2874064
60. 2728726  and 3077354
61. 2739704  and 2928136
62. 2802416  and 2947216
63. 2803580  and 3716164
64. 3276856  and 3721544
65. 3606850  and 3892670
66. 3786904  and 4300136
67. 3805264  and 4006736
68. 4238984  and 4314616
69. 4246130  and 4488910
70. 4259750  and 4445050
71. 4482765  and 5120595
72. 4532710  and 6135962
73. 4604776  and 5162744
74. 5123090  and 5504110
75. 5147032  and 5843048
76. 5232010  and 5799542
77. 5357625  and 5684679
78. 5385310  and 5812130
79. 5459176  and 5495264
80. 5726072  and 6369928
81. 5730615  and 6088905
82. 5864660  and 7489324
83. 6329416  and 6371384
84. 6377175  and 6680025
85. 6955216  and 7418864
86. 6993610  and 7158710
87. 7275532  and 7471508
88. 7288930  and 8221598
89. 7489112  and 7674088
90. 7577350  and 8493050
91. 7677248  and 7684672
92. 7800544  and 7916696
93. 7850512  and 8052488
94. 8262136  and 8369864
95. 8619765  and 9627915
96. 8666860  and 10638356
97. 8754130  and 10893230
98. 8826070  and 10043690
99. 9071685  and 9498555
100. 9199496  and 9592504
101. 9206925  and 10791795
102. 9339704  and 9892936
103. 9363584  and 9437056
104. 9478910  and 11049730
105. 9491625  and 10950615
106. 9660950  and 10025290
107. 9773505  and 11791935
108. 10254970  and 10273670
109. 10533296  and 10949704
110. 10572550  and 10854650
111. 10596368  and 11199112
112. 10634085  and 14084763
113. 10992735  and 12070305
114. 11173460  and 13212076
115. 11252648  and 12101272
116. 11498355  and 12024045
117. 11545616  and 12247504
118. 11693290  and 12361622
119. 11905504  and 13337336
120. 12397552  and 13136528
121. 12707704  and 14236136
122. 13671735  and 15877065
123. 13813150  and 14310050
124. 13921528  and 13985672
125. 14311688  and 14718712
126. 14426230  and 18087818
127. 14443730  and 15882670
128. 14654150  and 16817050
129. 15002464  and 15334304
130. 15363832  and 16517768
131. 15938055  and 17308665
132. 16137628  and 16150628
133. 16871582  and 19325698
134. 17041010  and 19150222
135. 17257695  and 17578785
136. 17754165  and 19985355
137. 17844255  and 19895265
138. 17908064  and 18017056
139. 18056312  and 18166888
140. 18194715  and 22240485
141. 18655744  and 19154336
142. 20014808  and 21457192
143. 20022328  and 22823432
144. 20308995  and 20955645
145. 21448630  and 23030090
146. 22227075  and 24644925
147. 22249552  and 25325528
148. 22508145  and 23111055
149. 22608632  and 25775368
150. 23358248  and 25233112
151. 23389695  and 25132545
152. 23628940  and 27428276
153. 24472180  and 30395276
154. 25596544  and 25640096
155. 25966832  and 26529808
156. 26090325  and 26138475
157. 28118032  and 28128368
158. 28608424  and 29603576
159. 30724694  and 32174506
160. 30830696  and 31652704
161. 31536855  and 32148585
162. 31818952  and 34860248
163. 32205616  and 34352624
164. 32642324  and 35095276
165. 32685250  and 34538270
166. 33501825  and 36136575
167. 34256222  and 35997346
168. 34364912  and 34380688
169. 34765731  and 36939357
170. 35115795  and 43266285
171. 35361326  and 40117714
172. 35373195  and 40105845
173. 35390008  and 39259592
174. 35472592  and 36415664
175. 37363095  and 45663849
176. 37784810  and 39944086
177. 37848915  and 39202605
178. 38400512  and 38938288
179. 38637016  and 40678184
180. 38663950  and 43362050
181. 38783992  and 41654408
182. 38807968  and 40912232
183. 43096904  and 46715896
184. 44139856  and 44916944
185. 45263384  and 46137016
186. 46237730  and 61319902
187. 46271745  and 49125375
188. 46521405  and 53011395
189. 46555250  and 55880590
190. 46991890  and 48471470
191. 48639032  and 52967368
192. 48641584  and 48852176
193. 49215166  and 55349570
194. 50997596  and 51737764
195. 52695376  and 56208368
196. 56055872  and 56598208
197. 56512610  and 75866014
198. 56924192  and 64562488
199. 58580540  and 70507972
200. 59497888  and 61953512
201. 63560025  and 65003175
202. 63717615  and 66011985
203. 66595130  and 74824390
204. 66854710  and 71946890
205. 67729064  and 69439576
206. 67738268  and 79732132
207. 68891992  and 78437288
208. 71015260  and 85458596
209. 71241830  and 78057370
210. 72958556  and 74733604
211. 73032872  and 78469528
212. 74055952  and 78166448
213. 74386305  and 87354495
214. 74769345  and 82824255
215. 75171808  and 77237792
216. 75226888  and 81265112
217. 78088504  and 88110536
218. 78447010  and 80960990
219. 79324875  and 87133365
220. 80422335  and 82977345
221. 83135650  and 85603550
222. 84591405  and 89590995
223. 86158220  and 99188788
224. 89477984  and 92143456
225. 90437150  and 94372450
226. 91996816  and 93259184
227. 93837808  and 99899792
228. 95629904  and 97580944
229. 96304845  and 96747315
230. 97041735  and 97945785
Run time for amicable 14.1404 secs


#endif

#if 0 

num: amicable Pair : 6 6
num: amicable Pair : 28 28
num: amicable Pair : 220 284
num: amicable Pair : 284 220
num: amicable Pair : 496 496
num: amicable Pair : 1184 1210
num: amicable Pair : 1210 1184
num: amicable Pair : 2620 2924
num: amicable Pair : 2924 2620
num: amicable Pair : 5020 5564
num: amicable Pair : 5564 5020
num: amicable Pair : 6232 6368
num: amicable Pair : 6368 6232
num: amicable Pair : 8128 8128
num: amicable Pair : 10744 10856
num: amicable Pair : 10856 10744
num: amicable Pair : 12285 14595
num: amicable Pair : 14595 12285
num: amicable Pair : 17296 18416
num: amicable Pair : 18416 17296
num: amicable Pair : 63020 76084
num: amicable Pair : 66928 66992
num: amicable Pair : 66992 66928
num: amicable Pair : 67095 71145
num: amicable Pair : 69615 87633
num: amicable Pair : 71145 67095
num: amicable Pair : 76084 63020
num: amicable Pair : 79750 88730
num: amicable Pair : 87633 69615
num: amicable Pair : 88730 79750
num: amicable Pair : 100485 124155
num: amicable Pair : 122265 139815
num: amicable Pair : 122368 123152
num: amicable Pair : 123152 122368
num: amicable Pair : 124155 100485
num: amicable Pair : 139815 122265
num: amicable Pair : 141664 153176
num: amicable Pair : 142310 168730
num: amicable Pair : 153176 141664
num: amicable Pair : 168730 142310
num: amicable Pair : 171856 176336
num: amicable Pair : 176272 180848
num: amicable Pair : 176336 171856
num: amicable Pair : 180848 176272
num: amicable Pair : 185368 203432
num: amicable Pair : 196724 202444
num: amicable Pair : 202444 196724
num: amicable Pair : 203432 185368
num: amicable Pair : 280540 365084
num: amicable Pair : 308620 389924
num: amicable Pair : 319550 430402
num: amicable Pair : 356408 399592
num: amicable Pair : 365084 280540
num: amicable Pair : 389924 308620
num: amicable Pair : 399592 356408
num: amicable Pair : 430402 319550
num: amicable Pair : 437456 455344
num: amicable Pair : 455344 437456
num: amicable Pair : 469028 486178
num: amicable Pair : 486178 469028
num: amicable Pair : 503056 514736
num: amicable Pair : 514736 503056
num: amicable Pair : 522405 525915
num: amicable Pair : 525915 522405
num: amicable Pair : 600392 669688
num: amicable Pair : 609928 686072
num: amicable Pair : 624184 691256
num: amicable Pair : 635624 712216
num: amicable Pair : 643336 652664
num: amicable Pair : 652664 643336
num: amicable Pair : 667964 783556
num: amicable Pair : 669688 600392
num: amicable Pair : 686072 609928
num: amicable Pair : 691256 624184
num: amicable Pair : 712216 635624
num: amicable Pair : 726104 796696
num: amicable Pair : 783556 667964
num: amicable Pair : 796696 726104
num: amicable Pair : 802725 863835
num: amicable Pair : 863835 802725
num: amicable Pair : 879712 901424
num: amicable Pair : 898216 980984
num: amicable Pair : 901424 879712
num: amicable Pair : 947835 1125765
num: amicable Pair : 980984 898216
num: amicable Pair : 998104 1043096
num: amicable Pair : 1043096 998104
num: amicable Pair : 1077890 1099390
num: amicable Pair : 1099390 1077890
num: amicable Pair : 1125765 947835
num: amicable Pair : 1154450 1189150
num: amicable Pair : 1156870 1292570
num: amicable Pair : 1175265 1438983
num: amicable Pair : 1185376 1286744
num: amicable Pair : 1189150 1154450
num: amicable Pair : 1280565 1340235
num: amicable Pair : 1286744 1185376
num: amicable Pair : 1292570 1156870
num: amicable Pair : 1328470 1483850
num: amicable Pair : 1340235 1280565
num: amicable Pair : 1358595 1486845
num: amicable Pair : 1392368 1464592
num: amicable Pair : 1438983 1175265
num: amicable Pair : 1464592 1392368
num: amicable Pair : 1466150 1747930
num: amicable Pair : 1468324 1749212
num: amicable Pair : 1483850 1328470
num: amicable Pair : 1486845 1358595
num: amicable Pair : 1511930 1598470
num: amicable Pair : 1598470 1511930
num: amicable Pair : 1669910 2062570
num: amicable Pair : 1747930 1466150
num: amicable Pair : 1749212 1468324
num: amicable Pair : 1798875 1870245
num: amicable Pair : 1870245 1798875
num: amicable Pair : 2062570 1669910
num: amicable Pair : 2082464 2090656
num: amicable Pair : 2090656 2082464
num: amicable Pair : 2236570 2429030
num: amicable Pair : 2429030 2236570
num: amicable Pair : 2652728 2941672
num: amicable Pair : 2723792 2874064
num: amicable Pair : 2728726 3077354
num: amicable Pair : 2739704 2928136
num: amicable Pair : 2802416 2947216
num: amicable Pair : 2803580 3716164
num: amicable Pair : 2874064 2723792
num: amicable Pair : 2928136 2739704
num: amicable Pair : 2941672 2652728
num: amicable Pair : 2947216 2802416
num: amicable Pair : 3077354 2728726
num: amicable Pair : 3276856 3721544
num: amicable Pair : 3606850 3892670
num: amicable Pair : 3716164 2803580
num: amicable Pair : 3721544 3276856
num: amicable Pair : 3786904 4300136
num: amicable Pair : 3805264 4006736
num: amicable Pair : 3892670 3606850
num: amicable Pair : 4006736 3805264
num: amicable Pair : 4238984 4314616
num: amicable Pair : 4246130 4488910
num: amicable Pair : 4259750 4445050
num: amicable Pair : 4300136 3786904
num: amicable Pair : 4314616 4238984
num: amicable Pair : 4445050 4259750
num: amicable Pair : 4482765 5120595
num: amicable Pair : 4488910 4246130
num: amicable Pair : 4532710 6135962
num: amicable Pair : 4604776 5162744
num: amicable Pair : 5120595 4482765
num: amicable Pair : 5123090 5504110
num: amicable Pair : 5147032 5843048
num: amicable Pair : 5162744 4604776
num: amicable Pair : 5232010 5799542
num: amicable Pair : 5357625 5684679
num: amicable Pair : 5385310 5812130
num: amicable Pair : 5459176 5495264
num: amicable Pair : 5495264 5459176
num: amicable Pair : 5504110 5123090
num: amicable Pair : 5684679 5357625
num: amicable Pair : 5726072 6369928
num: amicable Pair : 5730615 6088905
num: amicable Pair : 5799542 5232010
num: amicable Pair : 5812130 5385310
num: amicable Pair : 5843048 5147032
num: amicable Pair : 5864660 7489324
num: amicable Pair : 6088905 5730615
num: amicable Pair : 6135962 4532710
num: amicable Pair : 6329416 6371384
num: amicable Pair : 6369928 5726072
num: amicable Pair : 6371384 6329416
num: amicable Pair : 6377175 6680025
num: amicable Pair : 6680025 6377175
num: amicable Pair : 6955216 7418864
num: amicable Pair : 6993610 7158710
num: amicable Pair : 7158710 6993610
num: amicable Pair : 7275532 7471508
num: amicable Pair : 7288930 8221598
num: amicable Pair : 7418864 6955216
num: amicable Pair : 7471508 7275532
num: amicable Pair : 7489112 7674088
num: amicable Pair : 7489324 5864660
num: amicable Pair : 7577350 8493050
num: amicable Pair : 7674088 7489112
num: amicable Pair : 7677248 7684672
num: amicable Pair : 7684672 7677248
num: amicable Pair : 7800544 7916696
num: amicable Pair : 7850512 8052488
num: amicable Pair : 7916696 7800544
num: amicable Pair : 8052488 7850512
num: amicable Pair : 8221598 7288930
num: amicable Pair : 8262136 8369864
num: amicable Pair : 8369864 8262136
num: amicable Pair : 8493050 7577350
num: amicable Pair : 8619765 9627915

#endif

