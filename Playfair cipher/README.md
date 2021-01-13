# Playfair cipher

The Playfair cipher is an encryption algorithm performing a symmetric encryption.

Each letter is replaced with another letter following 4 simple rules.

A 5x5 matrix is ​​used by inserting the key inside it and the alphabet by eliminating repetitions.

If the 'esempiochiave' key is used, the 5x5 matrix is ​​the following

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
            <td>e</td>
            <td>s</td>
            <td>m</td>
            <td>p</td>
            <td>i</td>
        </tr>
        <tr>
            <td><code>2</code></td>
            <td>o</td>
            <td>c</td>
            <td>h</td>
            <td>a</td>
            <td>v</td>
        </tr>
        <tr>
            <td><code>3</code></td>
            <td>b</td>
            <td>d</td>
            <td>f</td>
            <td>g</td>
            <td>k</td>
        </tr>
        <tr>
            <td><code>4</code></td>
            <td>l</td>
            <td>n</td>
            <td>q</td>
            <td>r</td>
            <td>t</td>
        </tr>
       <tr>
            <td><code>5</code></td>
            <td>u</td>
            <td>w</td>
            <td>x</td>
            <td>y</td>
            <td>z</td>
        </tr>
    </tbody>
  </table>

Note how i = j is considered in this case as there are only 25 positions available.

The first thing to do is to divide the string to be encrypted into digraphs.

The rules to follow are as follows, considering each digraph:

1. If both letters are the same (or single), add an 'X' after the first letter.
2. If the two letters are on the same line, replace them with the two letters following them on the right.
3. If the two letters are on the same column, take the two letters below.
4. The letters of the digraph are coded considering the opposite corners of the rectangle defined by the couple.


Let's see an example.

If I take the string 'ciao come stai' I get 'ci ao co me st ai'.

- 'ci' follows rule 4 and translates to 'vs'.
- 'ao' follows rule 2 and translates to 'vc'.
- 'co' follows rule 2 and translates to 'hc'
- 'me' follows rule 2 and translates to 'ps'
- 'st' follows rule 4 and translates you as 'in'.
- 'ai' follows rule 4 and translates to 'vp'.

For simplicity we choose the international alphabet composed of 26 lowercase characters

![Playfair cipher](https://github.com/mariocuomo/encryption_methods/blob/main/images/playfaircipher.png)
