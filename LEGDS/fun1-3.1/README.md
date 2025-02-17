### 合并两个有序集，求中位数问题中的数学证明

#### 问题描述
有序集$S_1$与有序集$S_2$，长度分别为$L_1$与$L_2$，中位数的较小者与较大者分别为$M_1$与$M_2$。合并后集合$S_3$的中位数是$M_3$，证明：$M_1$ <= $M_3$ <= $M_2$。

#### 证明过程
先证$M_1$ <= $M_3$部分。反证：设$M_1$ > $M_3$，在$S_1$中比$M_1$大的有$L_1 - \lfloor \frac{L_1+1}{2} \rfloor$，在$S_2$中比$M_1$大的至少有$L_2 - \lfloor \frac{L_2+1}{2} \rfloor +1$，则在S_3中比M_1大的至少有:
$$
    L_1 - \lfloor \frac{L_1+1}{2} \rfloor + L_2 - \lfloor \frac{L_2+1}{2} \rfloor + 1 = L_1 + L_2 + 1 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor )
$$
又因，$M_1$ > $M_3$，且在$S_3$中比$M_3$大的有$L_1 + L_2 - \lfloor \frac{L_1+L_2+1}{2} \rfloor$，因此在$S_3$中比$M_1$大的至多有$L_1 + L_2 - \lfloor \frac{L_1+L_2+1}{2} \rfloor - 1$，计算：
$$
\begin{align*}
    &\quad L_1 + L_2 + 1 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor ) - (L_1 + L_2 - \lfloor \frac{L_1+L_2+1}{2} \rfloor - 1) \\
    &= \lfloor \frac{L_1+L_2+1}{2} \rfloor + 2 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor )
    \end{align*}
$$

- 若$lL_1 + L_2l$ 为偶数则:
$$
\begin{align}
    & \quad \lfloor \frac{L_1+L_2+1}{2} \rfloor = \lfloor \frac{L_1+L_2}{2} \rfloor \\
\end{align}
$$

1. 若$L_1$与$L_2$同为偶数:
$$
\begin{align}
    & \quad \lfloor \frac{L_1+1}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor \\
    & \quad \lfloor \frac{L_2+1}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor \\
    & \quad \lfloor \frac{L_1 + L_2}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor + \lfloor \frac{L_2}{2} \rfloor
\end{align}
$$
则：
$$
\begin{align*}
    &\quad \lfloor \frac{L_1+L_2+1}{2} \rfloor + 2 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor ) \\
    &= \lfloor \frac{L_1+L_2}{2} \rfloor + 2 - ( \lfloor \frac{L_1}{2} \rfloor + \lfloor \frac{L_2}{2} \rfloor ) \\
    &= 2
\end{align*}
$$

2. 若$L_1$与$L_2$都是奇数时：
$$
\begin{align}
    & \lfloor \frac{L_1+1}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor + 1 \\
    & \lfloor \frac{L_2+1}{2} \rfloor = \lfloor \frac{L_2}{2} \rfloor + 1  \\
    & \lfloor \frac{L_1+L_2}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor + \lfloor \frac{L_2}{2} \rfloor + 1 \\
\end{align}
$$
则：
$$
\begin{align*}
    &\quad \lfloor \frac{L_1+L_2+1}{2} \rfloor + 2 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor ) \\
    &= \lfloor \frac{L_1+L_2}{2} \rfloor + 2 - (\lfloor \frac{L_1}{2} \rfloor + 1 + \lfloor \frac{L_2}{2} \rfloor + 1) \\
    &= \lfloor \frac{L_1+L_2}{2} \rfloor - (\lfloor \frac{L_1}{2} \rfloor + \lfloor \frac{L_2}{2} \rfloor ) \\
    &= 1
\end{align*}
$$
- 当$L_1+L_2$是奇数时，不妨取$L_1$为奇数,$L_2$为偶数：
$$
\begin{align}
    & \quad \lfloor \frac{L_2+1}{2} \rfloor = \lfloor \frac{L_2}{2} \rfloor \\
    & \quad \lfloor \frac{L_1+1}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor + 1 \\
    & \quad \lfloor \frac{L_1+L_2+1}{2} \rfloor = \lfloor \frac{L_1+L_2}{2} \rfloor + 1 \\
    & \quad \lfloor \frac{L_1+L_2}{2} \rfloor = \lfloor \frac{L_1}{2} \rfloor + \lfloor \frac{L_2}{2} \rfloor \\
\end{align}
$$
则：
$$
\begin{align*}
    &\quad \lfloor \frac{L_1+L_2+1}{2} \rfloor + 2 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor ) \\
    & = \lfloor \frac{L_1+L_2}{2} \rfloor + 3 - \lfloor \frac{L_1}{2} \rfloor - 1 - \lfloor \frac{L_2}{2} \rfloor \\
    & = 2 \\
\end{align*}
$$
综上，在$M_1 > M_3$时，在$S_3$中比$M_1$大的元素个数的最小值$L_1 + L_2 + 1 - ( \lfloor \frac{L_1+1}{2} \rfloor + \lfloor \frac{L_2+1}{2} \rfloor$严格大于最大值$L_1 + L_2 - \lfloor \frac{L_1+L_2+1}{2} \rfloor - 1$。
故矛盾，所以，$M_1 <= M_3$

---

证明$M_3 <= M_2$同理，往下便不再赘述。  
