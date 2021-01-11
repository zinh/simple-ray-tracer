Dependencies:

- [Boost 1.75.0](https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.gz)
  - test, timer

Config and build boost

```
./bootstrap.sh --with-libraries=test,timer
./b2 --prefix=<PREFIX> install
```
