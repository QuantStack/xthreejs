#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmaterial_base>;
template xw::xmaterialize<xthree::xmaterial_base>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmaterial_base>>;
template class xw::xgenerator<xthree::xmaterial_base>;
template xw::xgenerator<xthree::xmaterial_base>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmaterial_base>>;