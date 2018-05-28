#ifndef XTHREE_BONE_HPP
#define XTHREE_BONE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // bone declaration
    //

    template<class D>
    class xbone : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xbone();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using bone = xw::xmaterialize<xbone>;

    using bone_generator = xw::xgenerator<xbone>;

    //
    // bone implementation
    //


    template <class D>
    inline void xbone<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xbone<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xbone<D>::xbone()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbone<D>::set_defaults()
    {
        this->_model_name() = "BoneModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xbone>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xbone>;
        extern template xw::xmaterialize<xthree::xbone>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xbone>>;
        extern template class xw::xgenerator<xthree::xbone>;
        extern template xw::xgenerator<xthree::xbone>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xbone>>;
    #endif
#endif

#endif