#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xgrid_helper>;
template xw::xmaterialize<xthree::xgrid_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xgrid_helper>>;
template class xw::xgenerator<xthree::xgrid_helper>;
template xw::xgenerator<xthree::xgrid_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xgrid_helper>>;