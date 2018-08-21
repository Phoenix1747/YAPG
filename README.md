# YAPG
Very simple password generator. Generates any password size until it crashes.

You can choose from ~80 different characters:
* Uppercase letters
* Lowercase letters
* Numbers
* Special characters

### How to use

Just compile the `main.cpp` like so: `g++ main.cpp` and then just type `./a.out`.
If you've done everything right and fought your way through the program the output should look something like this:

```
$ ./a.out 
:: How long should your password be? [Default:10] 12
:: May contain lowercase letters? [Y/n] y
:: May contain uppercase letters? [Y/n] y
:: May contain numbers? [Y/n] y
:: May contain special characters? [Y/n] y
Finished! Your password is: B$Rgc~N43>@5
```

If you're on a x86_64 Linux system, you could also use my pre-compiled binaries down at the [releases section](https://github.com/Phoenix1747/YAPG/releases). However, I recommend compiling it for yourself, it's really quick and easy.
