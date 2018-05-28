#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlayers>;
template xw::xmaterialize<xthree::xlayers>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlayers>>;
template class xw::xgenerator<xthree::xlayers>;
template xw::xgenerator<xthree::xlayers>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlayers>>;