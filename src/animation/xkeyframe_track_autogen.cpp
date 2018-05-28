#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xkeyframe_track>;
template xw::xmaterialize<xthree::xkeyframe_track>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xkeyframe_track>>;
template class xw::xgenerator<xthree::xkeyframe_track>;
template xw::xgenerator<xthree::xkeyframe_track>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xkeyframe_track>>;