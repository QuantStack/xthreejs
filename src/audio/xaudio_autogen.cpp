#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xaudio>;
template xw::xmaterialize<xthree::xaudio>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xaudio>>;
template class xw::xgenerator<xthree::xaudio>;
template xw::xgenerator<xthree::xaudio>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xaudio>>;