# IDEA
1. **The celeb does NOT know anyone. But EVERYONE knows the celeb.**
2. This means that **knows(celeb, i) == false and knows(i, celeb) == true** always
3. *In the first pass we find for the only possible celeb:*
`int celeb = 0;`
`for(int i = 0; i < n; i++) if(knows(i, celeb) == false) celeb = i;`
4. *In the second pass we confirm whether the ONLY POSSIBLE CELEB is infact a celeb after all :*
`for(int i = 0; i < n; i++)`
`{`
`if((knows(celeb, i) == true) or (knows(i, celeb) == false)) return -1;`
`}`
`return celeb`