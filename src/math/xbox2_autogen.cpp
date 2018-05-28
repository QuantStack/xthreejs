#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbox2>;
template xw::xmaterialize<xthree::xbox2>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbox2>>;
template class xw::xgenerator<xthree::xbox2>;
template xw::xgenerator<xthree::xbox2>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbox2>>;