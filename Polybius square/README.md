# Polybius square

The Polybius chessboard is an encryption algorithm that converts characters into numbers.
Each letter is replaced with the corresponding coordinate in the following chessboard


<table>
    <thead>
      <tr>
        <th></th>
        <th><code>1</code></th>
        <th><code>2</code></th>
        <th><code>3</code></th>
        <th><code>4</code></th>
        <th><code>5</code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>1</code></td>
            <td>a</td>
            <td>b</td>
            <td>c</td>
            <td>d</td>
            <td>e</td>
        </tr>
        <tr>
            <td><code>2</code></td>
            <td>f</td>
            <td>g</td>
            <td>h</td>
            <td>i,j</td>
            <td>k</td>
        </tr>
        <tr>
            <td><code>3</code></td>
            <td>l</td>
            <td>m</td>
            <td>n</td>
            <td>o</td>
            <td>p</td>
        </tr>
        <tr>
            <td><code>4</code></td>
            <td>q</td>
            <td>r</td>
            <td>s</td>
            <td>t</td>
            <td>u</td>
        </tr>
       <tr>
            <td><code>5</code></td>
            <td>v</td>
            <td>w</td>
            <td>x</td>
            <td>y</td>
            <td>z</td>
        </tr>
    </tbody>
  </table>
Let's see an example.

If I take the string 'ab' I get '1112'

For simplicity we choose the international alphabet composed of 26 lowercase characters

![Polybius square](https://github.com/mariocuomo/encryption_methods/blob/main/images/polybiussquare.png)
