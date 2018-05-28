#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpath>;
template xw::xmaterialize<xthree::xpath>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpath>>;
template class xw::xgenerator<xthree::xpath>;
template xw::xgenerator<xthree::xpath>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpath>>;