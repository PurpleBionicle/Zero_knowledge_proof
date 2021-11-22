# authentication-protocol

<h3>Курсовая работа : </h3>

- [x] Протокол <br/>
  ![output](demonstration/pic/protocol_prover.png)

---

- [x] Атака повторного воспроизведения  <br/>
  ![attacker](demonstration/pic/attacker.png)
- [x] Визуализация  <br/>
  ![main page](demonstration/pic/main.png)
  ![prover](demonstration/pic/visual.png)
  <br/>

---
<h3>UML-диаграмма</h3>
![uml](demonstration/pic/uml.png)
<br/>
---
<h3>Процесс отладки раундов протокола</h3>

- [x] R=[k]*G <br/>

```c++
R = curve.get_G() * k;
```

- [x] Yi =∑[-xi]*G <br/>

```c++
for (int i = 0; i < m; ++i) {
        mpz_class mult = (-xi[i]) % curve.get_order();
        while (mult < 0) {
            mult += curve.get_order();
        }
        Y[i] = curve.get_G() * mult;
    }
```

- [x] ( a1, ..., am ) ∈ {0, 1}m<br/>

```c++
std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(
            0, std::numeric_limits<int>::max());

    int random = dist6(rng);
    mpz_class bit_string = random % static_cast<int>(pow(2, Y.size())); //длины m
```

- [x] s=k+aixi <br/>

```c++
s = k + (sum(binary_string)) % q;
```

- [x] R=[s]G+ ∑[ai]Yi

```c++
Point sG = curve.get_G() * s;
Point d = sum(binary, Y) + sG;
return R == d;
```
