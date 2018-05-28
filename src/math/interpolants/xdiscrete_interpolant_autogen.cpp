#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdiscrete_interpolant>;
template xw::xmaterialize<xthree::xdiscrete_interpolant>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdiscrete_interpolant>>;
template class xw::xgenerator<xthree::xdiscrete_interpolant>;
template xw::xgenerator<xthree::xdiscrete_interpolant>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdiscrete_interpolant>>;