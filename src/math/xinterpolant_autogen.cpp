#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xinterpolant>;
template xw::xmaterialize<xthree::xinterpolant>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xinterpolant>>;
template class xw::xgenerator<xthree::xinterpolant>;
template xw::xgenerator<xthree::xinterpolant>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xinterpolant>>;