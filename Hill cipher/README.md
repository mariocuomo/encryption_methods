# Hill cipher

The Hill Cipher is a polyalphabetic substitution cryptographic algorithm.

Each letter is replaced with a new letter by making a dot product with a matrix.

The matrix represents the key.

If I have a string of length n I need an nxn array

For simplicity we consider n = 3 and the following matrix as a key
<table>
    <thead>
      <tr>
        <th></th>
        <th><code>1</code></th>
        <th><code>2</code></th>
        <th><code>3</code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>1</code></td>
            <td>15</td>
            <td>2</td>
            <td>4</td>
        </tr>
        <tr>
            <td><code>2</code></td>
            <td>3</td>
            <td>13</td>
            <td>5</td>
        </tr>
        <tr>
            <td><code>3</code></td>
            <td>1</td>
            <td>3</td>
            <td>3</td>
        </tr>
    </tbody>
  </table>

Let's see an example.

If I take the string 'cde' I have to perform the following steps

c=2 d=3 e=4 represents the vector (2,3,4).

The first character is obtained as (2,3,4) x (15 2 4) = 2x15 + 3x2 + 4x4 = 30 + 6 + 16 = 52.

52mod26 returns 0 which represents 0. Replace the first character with 'a'.

The second character is obtained as (2,3,4) x (3 13 5) = 2x3 + 3x13 + 4x5 = 6 + 39 + 20 = 65.

65mod26 returns 13. Replace the second character with 'n'.

The third character is obtained as (2,3,4) x (1 3 3) = 2x1 + 3x3 + 4x3 = 2 + 9 + 12 = 23.

23mod26 returns 23. Replace the third character with 'x'.

For simplicity we choose the international alphabet consisting of 26 lowercase characters

![Hill cipher](https://github.com/mariocuomo/encryption_methods/blob/main/images/hillcipher.png)
