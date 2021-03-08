# 指针与const
1.指针是const的如：<br>
`int i;`<br>
`int * const p = &i`<br>
表示指针变量中的数据，即i的地址是const的<br>
`*p = 6;` 可以<br>
`p++;`不可以<br>
2.不可以用指针来修改变量的值<br>
`int i;`<br>
`const int *p = &i`<br>
`*p = 6;` 不可以<br>
`p = &j;`可以<br>
`i = 6;` 可以
