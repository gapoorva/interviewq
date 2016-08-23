# interviewq

This is a repository of technical (EECS) and non-technical (everyone) questions that are meant to help you prepare for you next interview. Whether your next interview is going to be a coding interview or a behavioral interview, you can look at real questions that people have answered. You can also contribute by adding your own questions!

If you don't know how to use Github don't worry! All you need is a text editor, the Github application and a Github account. Follow the directions in the [Github section](#github).

## Non technical

See the `nontechnical` folder for behavioral questions. These will be questions that you might hear in a behavioral interviews and sample responses from contributors.

### How to Contribute

When contributing to the repo, you'll want to make a branch with your username and use pull requests to update master. Take a look at the [Github section](#github) on how to do this.

If you'd like to add to questions here, create a folder for your question under `nontechnical`. Keep the name short, sweet and to the point. For example a good folder name for a question like "Why are you a good fit for this role?" might be `why_me`.

Then, create a file in the new folder called `readme.md`. **It's important that you name the file exactly this**. `.md` files are called Markdown, and when Github sees a file called `readme.md` in a folder, they'll format it nicely in the browser.

See the [Markdown section](#markdown) for a quick tutorial on how to write a Markdown file.

Then, go ahead and add your question and an answer. Make sure to take credit for your answer.

## Technical

The technical folder contains coding interview questions. This is great for implementing a few questions on your own and seeing solutions to problems in a variety of languages.

The technical folder will contain folders for different coding problems (and a book of coding problems). Each problem folder contains a `readme.md` that details the problem, may provide a few examples, and shows a table of current solutions for different languages and their runtime/space complexities. 

Each problem folder will also have a folder for each language in which a solution is implemented. For example, a `golang` folder would contain a solution to the problem written in the Go programming language.

Each language folder should contain source code and a `Makefile` that builds the code and runs a series of tests that demonstrate the correctness of the code when `make` is run. `make` should exit with a zero-status if the build and all tests pass.

If you are using a new language or trying to build a solution on your local computer in a new language make sure you follow directions in the [Setup Section](#setup) to set up your build environment.

### How to Contribute

To contribute to the technical folder, add a folder for the problem if it doesn't already exist. Then create a `readme.md` for the problem if it doesn't exist and add a description of the problem plus an example or two if appropriate.

See the [Markdown section](#markdown) for a quick tutorial on how to write a Markdown file.

Create a folder for the language you want to use in the problem folder. In the language folder, add a `Makefile` and your source code. Add tests for your solution and make sure calling `make` builds and tests your code. 

Once you have a working solution, add an entry to the solutions table in the `readme.md` for the problem, describing the language, time and space complexities of your solution and your name. If you add to an existing solution, make sure to give credit to yourself as well as past authors.

### Language Specific Setup Instructions <a name="setup"></a>

**Golang**

To work with golang, follow directions [here](https://golang.org/doc/install) to install Go and setup a `$GOPATH`. Clone this repo to `$GOPATH/src/github.com/gapoorva/interviewq`. You should be all good to go! 

## Markdown <a name="markdown"></a>

Here are some examples of the super-simple Markdown syntax. Scroll below to see what they output.

    # Header 1
    ## Header 2
    ### Header 3
    #### Header 4
    ##### Header 5

    Horizontal separator:
    ---

    *Italics* or _Italics_
    **Bold** or __Bold__
    ~~Strikethrough~~

    ---

    1. Ordered list
      1. Ordered Sublist
    2. Ordered list
      * Unordered Sublist

    * Unordered List
    * Apples
    - Bananas
    + Carrots

    ---

    Inline `code` has `backticks`

    ```
    Surround code with three backticks for a code block like this one
    ```

    ```javascript
    var s = "supports language-based syntax highlighting";
    ```
    ---

    | Awesome | Table |
    |---------|-------|
    | 293     | false |

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

Horizontal separator:
---

*Italics* or _Italics_
**Bold** or __Bold__
~~Strikethrough~~

---

1. Ordered list
  1. Ordered Sublist
2. Ordered list
  * Unordered Sublist

* Unordered List
* Apples
- Bananas
+ Carrots

---

Inline `code` has `backticks`

```
Surround code with three backticks for a code block like this one
```

```javascript
var s = "supports language-based syntax highlighting";
```
---

| Awesome | Table |
|---------|-------|
| 293     | false |


## Github <a name="github"></a>

To get started with Github and contribute to the repo do the following:

1. [Get a Github account](https://github.com/join)
2. Ask to become a contributer or fork the repository
3. [Download the Github UI](  https://desktop.github.com/) for your operating system.
4. In the UI, clone the repository to a location on your machine.
5. In the UI, make a branch with your name (or use your fork of the repo)
6. With a text editor, contribute to the project.
7. In the UI, make a pull request to the master branch on the repo (similar process for forks)
8. Get another collaborator to look at your work and merge it to master for everyone to learn from.
9. Rinse and Repeat (steps 6-8)

Want a better understanding of how Git works? There's a bunch of reading online, and [this tutorial](https://github.com/gapoorva/thetatauwebsite16/blob/master/GIT_TUTORIAL.md).