#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcamera>;
template xw::xmaterialize<xthree::xcamera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcamera>>;
template class xw::xgenerator<xthree::xcamera>;
template xw::xgenerator<xthree::xcamera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcamera>>;