#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpolar_grid_helper>;
template xw::xmaterialize<xthree::xpolar_grid_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpolar_grid_helper>>;
template class xw::xgenerator<xthree::xpolar_grid_helper>;
template xw::xgenerator<xthree::xpolar_grid_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpolar_grid_helper>>;