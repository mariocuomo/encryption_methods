# Vigenère cipher

The Vigenère cipher is a substitution encryption algorithm.

Each letter is replaced with another at a distance described by a key.

Let's see an example.

If I take the string 'ciao' and choose the key 'abba' I get 'cjbo'.

The code is cyclic, if I take the string 'yz' and choose the key 'dd' I get 'bc'.

For simplicity we choose the international alphabet consisting of 26 lowercase characters

![Vigenère cipher](https://github.com/mariocuomo/encryption_methods/blob/main/images/vigenerecipher.png)
