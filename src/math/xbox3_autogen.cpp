#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbox3>;
template xw::xmaterialize<xthree::xbox3>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbox3>>;
template class xw::xgenerator<xthree::xbox3>;
template xw::xgenerator<xthree::xbox3>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbox3>>;