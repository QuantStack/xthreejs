#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xplane_base>;
template xw::xmaterialize<xthree::xplane_base>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xplane_base>>;
template class xw::xgenerator<xthree::xplane_base>;
template xw::xgenerator<xthree::xplane_base>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xplane_base>>;