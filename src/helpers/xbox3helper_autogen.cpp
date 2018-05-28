#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbox3helper>;
template xw::xmaterialize<xthree::xbox3helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbox3helper>>;
template class xw::xgenerator<xthree::xbox3helper>;
template xw::xgenerator<xthree::xbox3helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbox3helper>>;