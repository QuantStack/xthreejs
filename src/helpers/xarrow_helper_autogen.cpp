#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xarrow_helper>;
template xw::xmaterialize<xthree::xarrow_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xarrow_helper>>;
template class xw::xgenerator<xthree::xarrow_helper>;
template xw::xgenerator<xthree::xarrow_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xarrow_helper>>;