# Polybius square

The Polybius chessboard is an encryption algorithm that converts characters into numbers.
Each letter is replaced with the corresponding coordinate in the following chessboard


<table>
    <thead>
      <tr>
        <th></th>
        <th>1</th>
        <th>2</th>
        <th>3</th>
        <th>4</th>
        <th>5</th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>a</td>
            <td>b</td>
            <td><code>c</code></td>
            <td><code>d</code></td>
            <td><code>e</code></td>
        </tr>
        <tr>
            <td>2</td>
            <td>f</td>
            <td>g</td>
            <td><code>h</code></td>
            <td><code>i,j</code></td>
            <td><code>k</code></td>
        </tr>
        <tr>
            <td>3</td>
            <td>l</td>
            <td>m</td>
            <td><code>n</code></td>
            <td><code>o</code></td>
            <td><code>p</code></td>
        </tr>
        <tr>
            <td>4</td>
            <td>q</td>
            <td>r</td>
            <td><code>s</code></td>
            <td><code>t</code></td>
            <td><code>u</code></td>
        </tr>
       <tr>
            <td>5</td>
            <td>v</td>
            <td>w</td>
            <td><code>x</code></td>
            <td><code>y</code></td>
            <td><code>z</code></td>
        </tr>
    </tbody>
  </table>
Let's see an example.

If I take the string 'ab' I get '1112'

For simplicity we choose the international alphabet composed of 26 lowercase characters

![Polybius square](https://github.com/mariocuomo/encryption_methods/blob/main/images/polybiussquare.png)
