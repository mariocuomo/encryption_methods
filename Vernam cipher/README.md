# Vernam cipher

Vernam's cipher is a substitution encryption algorithm.

The necessary condition for guaranteeing security is that the key has the same length as the word to be encrypted.

For simplicity we use a long key 5, 'gatto'.

The xOR is carried out between the bits following the Baudot code.

Here is the Baudot code table.

<table>
    <thead>
      <tr>
        <th>LETTER</th>
        <th><code></code></th>
        <th><code></code></th>
        <th><code></code></th>
        <th><code></code></th>
        <th><code></code></th>
      </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>A</code></td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
        <tr>
            <td><code>B</code></td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>C</code></td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
        </tr>
        <tr>
            <td><code>D</code></td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
        </tr>
       <tr>
            <td><code>E</code></td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
       <tr>
            <td><code>F</code></td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
        </tr>
       <tr>
            <td><code>G</code></td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
        </tr>
		<tr>
            <td><code>H</code></td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
        </tr>
       	<tr>
            <td><code>I</code></td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
        </tr>
   		<tr>
            <td><code>J</code></td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
        </tr>
        <tr>
            <td><code>K</code></td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
        </tr>
       	<tr>
            <td><code>L</code></td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>M</code></td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>N</code></td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
        </tr>
       	<tr>
            <td><code>O</code></td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>P</code></td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>Q</code></td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
        </tr>
       	<tr>
            <td><code>R</code></td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
        </tr>
       	<tr>
            <td><code>S</code></td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
        </tr>
        <tr>
            <td><code>T</code></td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>U</code></td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
        </tr>
       	<tr>
            <td><code>V</code></td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>W</code></td>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>X</code></td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>Y</code></td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td><code>Z</code></td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
    </tbody>

  </table>

With 5 bits it is possible to make 32 combinations.

The remaining combinations represent numbers and special characters.

Suppose the remaining combinations all represent the special character '0'.

Let's see an example.

If I take the string 'pippo' with the key 'gatto' I get 'nsii0'.

'p' is translated as 01101.

'g' is translated with 01011.

The xOR between the two is' '00110' which represents the letter 'n'.

The remaining letters follow the same rule.

For simplicity we choose the international alphabet composed of 26 lowercase characters

![Vernam cipher](https://github.com/mariocuomo/encryption_methods/blob/main/images/vernamrcipher.png)
