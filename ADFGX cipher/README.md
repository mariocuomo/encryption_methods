# ADFGX square

The ADFGX cipher is a transposition cryptographic method with fractionation.

It is named ADFGX because these are the only letters that appear in the final encrypted message.

We consider a 5x5 matrix with the alphabet mixed considering i = j.

The matrix we consider is the following

<table>
    <thead>
      <tr>
        <th></th>
        <th><code>A</code></th>
        <th><code>D</code></th>
        <th><code>F</code></th>
        <th><code>G</code></th>
        <th><code>X</code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>A</code></td>
            <td>b</td>
            <td>t</td>
            <td>a</td>
            <td>l</td>
            <td>p</td>
        </tr>
        <tr>
            <td><code>D</code></td>
            <td>d</td>
            <td>h</td>
            <td>o</td>
            <td>z</td>
            <td>k</td>
        </tr>
        <tr>
            <td><code>F</code></td>
            <td>q</td>
            <td>f</td>
            <td>v</td>
            <td>s</td>
            <td>n</td>
        </tr>
        <tr>
            <td><code>G</code></td>
            <td>g</td>
            <td>i</td>
            <td>c</td>
            <td>u</td>
            <td>x</td>
        </tr>
       <tr>
            <td><code>X</code></td>
            <td>m</td>
            <td>r</td>
            <td>e</td>
            <td>w</td>
            <td>y</td>
        </tr>
    </tbody>
  </table>

Let's see an example.


If I take the string 'ciao come stai' the first thing to do is to decipher it as it happens in the Polybius code.

REMEMBER: each letter is replaced by the row/column pair.

Instead of 'ciao' you get 'GF GD AF DF'.

Instead of 'come' you get 'GF DF XA XF'.

Instead of 'stai' you get 'FG AD AF GD'.

The final string is GF GD AF DF GF DF XA XF FG AD AF GD.

At this point we consider a key and for simplicity we choose it of 5 characters.

The key we consider is 'ZAINO'.

A matrix of 5 (because the key is 5 long) columns is constructed.

You write the encrypted message in it starting from left to right and top to bottom.

In the example the result is the following

<table>
    <thead>
      <tr>
        <th><code>Z</code></th>
        <th><code>A</code></th>
        <th><code>I</code></th>
        <th><code>N</code></th>
        <th><code>O</code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td>G</td>
            <td>F</td>
            <td>G</td>
            <td>D</td>
            <td>A</td>
        </tr>
        <tr>
            <td>F</td>
            <td>D</td>
            <td>F</td>
            <td>G</td>
            <td>F</td>
        </tr>
        <tr>
            <td>D</td>
            <td>F</td>
            <td>X</td>
            <td>A</td>
            <td>X</td>
        </tr>
        <tr>
            <td>F</td>
            <td>F</td>
            <td>G</td>
            <td>A</td>
            <td>D</td>
        </tr>
       <tr>
            <td>A</td>
            <td>F</td>
            <td>G</td>
            <td>D</td>
            <td> </td>
        </tr>
    </tbody>
  </table>

At this point, the columnar transposition is carried out by alphabetizing the key.

The resulting matrix is ​​the following

<table>
    <thead>
      <tr>
        <th><code>A</code></th>
        <th><code>I</code></th>
        <th><code>N</code></th>
        <th><code>O</code></th>
        <th><code>Z</code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td>F</td>
            <td>G</td>
            <td>D</td>
            <td>A</td>
            <td>G</td>
        </tr>
        <tr>
            <td>D</td>
            <td>F</td>
            <td>G</td>
            <td>F</td>
            <td>F</td>
        </tr>
        <tr>
            <td>F</td>
            <td>X</td>
            <td>A</td>
            <td>X</td>
            <td>D</td>
        </tr>
        <tr>
            <td>F</td>
            <td>G</td>
            <td>A</td>
            <td>D</td>
            <td>F</td>
        </tr>
       <tr>
            <td>F</td>
            <td>G</td>
            <td>D</td>
            <td> </td>
            <td>A</td>
        </tr>
    </tbody>
  </table>

The last step is to extract the encrypted message column by column starting from top to bottom and from left to right.

The encrypted message is the following FDFFF GFXGG DGAAD AFXD GFDFA.

For simplicity we choose the international alphabet composed of 26 lowercase characters

![ADFGX square](https://github.com/mariocuomo/encryption_methods/blob/main/images/ADFGXcipher.png)
