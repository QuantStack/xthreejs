#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xaudio_loader>;
template xw::xmaterialize<xthree::xaudio_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xaudio_loader>>;
template class xw::xgenerator<xthree::xaudio_loader>;
template xw::xgenerator<xthree::xaudio_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xaudio_loader>>;