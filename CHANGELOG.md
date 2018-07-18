# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

<!-- For new contributors use this format for adding items to the changelog
- [[#PR](https://github.com/tortleog/transaction_tracker/pull/PR)] Change Proposed. (author)
 **or**
- [[#commit](https://github.com/tortleog/transaction_tracker/commit/COMMIT)] Changed Porposed. (author)
-->

## [Unreleased]
### Added
- [[#6d1dee1](https://github.com/tortleog/transaction_tracker/commit/6d1dee132f94c4b851b67d989e7d2891f6acce99)] added loader for transaction files. (tortleog)
- [[#6d1dee1](https://github.com/tortleog/transaction_tracker/commit/6d1dee132f94c4b851b67d989e7d2891f6acce99)] Added 'exit' menu option to exit the program. (tortleog)
- [[#4e0cbe7](https://github.com/tortleog/transaction_tracker/commit/4e0cbe714ccfbd351b9c11077b5398173db6549f)] Added setters for Transaction. (tortleog)
- [[#4e0cbe7](https://github.com/tortleog/transaction_tracker/commit/4e0cbe714ccfbd351b9c11077b5398173db6549f)] Added Transaction constructor which takes a last id, to create new transactions with the known id of the last transaction. (tortleog)
- [[#4e0cbe7](https://github.com/tortleog/transaction_tracker/commit/4e0cbe714ccfbd351b9c11077b5398173db6549f)] Added >> & << operators for transaction to create and output transactions. (tortleog)
- [[#4e0cbe7](https://github.com/tortleog/transaction_tracker/commit/4e0cbe714ccfbd351b9c11077b5398173db6549f)] Added default Transaction constructor. (tortleog)
- [[#44005d7](https://github.com/tortleog/transaction_tracker/commit/44005d7e36f4764e3455c6043ebdb0df3a08d585)] Added setters to Menu. (tortleog)
- [[#44005d7](https://github.com/tortleog/transaction_tracker/commit/44005d7e36f4764e3455c6043ebdb0df3a08d585)] Added >> operators to control menu input. (tortleog)
- [[#44005d7](https://github.com/tortleog/transaction_tracker/commit/44005d7e36f4764e3455c6043ebdb0df3a08d585)] Added default Menu contructor. (tortleog)
- [[#2694178](https://github.com/tortleog/transaction_tracker/commit/2694178c99762ab414e60d78fc79a92858459074)] Added Loader clss to load transaction files. (tortleog)
- [[#e1b1eac](https://github.com/TortleOG/transaction_tracker/commit/e1b1eaca70b4bf111999cdde9e74454aa9548f28)] Added Transaction class. (tortleog)
- [[#132c02a](https://github.com/tortleog/transaction_tracker/commit/132c02a36ecc3a0c5d3936d801c5ec57e37ba16f)] Added a menu class to easily create new menus. (tortleog)
- [[#1](https://github.com/tortleog/transaction_tracker/pull/1)] Added transaction struct. (tortleog)
- [[#1](https://github.com/tortleog/transaction_tracker/pull/1)] Added transaction creation. (tortleog)
- [[#1](https://github.com/tortleog/transaction_tracker/pull/1)] Added util functions to help with transaction creation. (tortleog)
- [[#1](https://github.com/tortleog/transaction_tracker/pull/1)] Added function to print transactiond data. (tortleog)
- [[#359d5ab](https://github.com/tortleog/transaction_tracker/commit/359d5ab9d84bfbbe9770f9101967e32a30e8675f)] Added the menu screen for ease of use. (tortleog)

### Removed
- [[#e1b1eac](https://github.com/TortleOG/transaction_tracker/commit/e1b1eaca70b4bf111999cdde9e74454aa9548f28)] Removed transaction struct. (tortleog)
- [[#e1b1eac](https://github.com/TortleOG/transaction_tracker/commit/e1b1eaca70b4bf111999cdde9e74454aa9548f28)] Removed functions for classes. (tortleog)

### Changed
- [[#6d1dee1](https://github.com/tortleog/transaction_tracker/commit/6d1dee132f94c4b851b67d989e7d2891f6acce99)] Updated menu callbacks. (tortleog)
- [[#6b83068](https://github.com/tortleog/transaction_tracker/commit/6b83068be93aee6ba3742ecb3ae87f6bdeb4825d)] Updated Menu#add to allow for an optional callback parameter on menu options. (tortleog)
- [[#ba144cb](https://github.com/tortleog/transaction_tracker/commit/ba144cb4acae9f23d1c4be77a76ccdf85a9ceda8)] Changed menu parameters to pass by reference. (tortleog)
- [[#e1b1eac](https://github.com/TortleOG/transaction_tracker/commit/e1b1eaca70b4bf111999cdde9e74454aa9548f28)] Moved get_date into header file. (tortleog)
- [[#e1b1eac](https://github.com/TortleOG/transaction_tracker/commit/e1b1eaca70b4bf111999cdde9e74454aa9548f28)] Changed get_date to create_date. (tortleog)
