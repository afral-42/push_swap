$$
\begin{array}{r|l|l}
\textbf{\#} & \textbf{Code} & \textbf{Complexité} \\ \hline
1 & \textbf{Algorithme} \text{ RechercheBinaire}(A, n, x): & - \\
2 & \quad \textbf{Entrée: } \text{Un tableau trié } A, \dots & - \\
3 & \quad \textbf{Sortie: } \text{Indice de } x \text{ ou } -1 & - \\
4 & & \\
5 & \quad bas \leftarrow 0 & \mathcal{O}(1) \\
6 & \quad haut \leftarrow n - 1 & \mathcal{O}(1) \\
7 & & \\
8 & \quad \textbf{Tant que } bas \le haut \textbf{ faire}: & \mathcal{O}(\log n) \\
9 & \quad \quad milieu \leftarrow \lfloor (bas + haut) / 2 \rfloor & \mathcal{O}(1) \\
10 & & \\
11 & \quad \quad \textbf{Si } A[milieu] = x \textbf{ alors}: & \mathcal{O}(1) \\
12 & \quad \quad \quad \textbf{Retourner } milieu & \mathcal{O}(1) \\
13 & \quad \quad \textbf{Sinon si } A[milieu] < x \textbf{ alors}: & \mathcal{O}(1) \\
14 & \quad \quad \quad bas \leftarrow milieu + 1 & \mathcal{O}(1) \\
15 & \quad \quad \textbf{Sinon}: & \\
16 & \quad \quad \quad haut \leftarrow milieu - 1 & \mathcal{O}(1) \\
17 & & \\
18 & \quad \textbf{Retourner } -1 & \mathcal{O}(1)
\end{array}
$$