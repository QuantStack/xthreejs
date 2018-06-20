#ifndef XTHREE_LAYERS_HPP
#define XTHREE_LAYERS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // layers declaration
    //

    template<class D>
    class xlayers : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xlayers();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using layers = xw::xmaterialize<xlayers>;

    using layers_generator = xw::xgenerator<xlayers>;

    //
    // layers implementation
    //


    template <class D>
    inline void xlayers<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xlayers<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xlayers<D>::xlayers()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlayers<D>::set_defaults()
    {
        this->_model_name() = "LayersModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xlayers>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xlayers>;
        extern template xw::xmaterialize<xthree::xlayers>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xlayers>>;
        extern template class xw::xgenerator<xthree::xlayers>;
        extern template xw::xgenerator<xthree::xlayers>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xlayers>>;
    #endif
#endif

#endif