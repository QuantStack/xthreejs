#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xray>;
template xw::xmaterialize<xthree::xray>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xray>>;
template class xw::xgenerator<xthree::xray>;
template xw::xgenerator<xthree::xray>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xray>>;