#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xperspective_camera>;
template xw::xmaterialize<xthree::xperspective_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xperspective_camera>>;
template class xw::xgenerator<xthree::xperspective_camera>;
template xw::xgenerator<xthree::xperspective_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xperspective_camera>>;