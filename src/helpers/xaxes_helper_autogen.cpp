#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xaxes_helper>;
template xw::xmaterialize<xthree::xaxes_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xaxes_helper>>;
template class xw::xgenerator<xthree::xaxes_helper>;
template xw::xgenerator<xthree::xaxes_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xaxes_helper>>;